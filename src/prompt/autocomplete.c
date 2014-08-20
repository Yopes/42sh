/*
** autocomplete.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Thu May 15 13:10:47 2014 menigo_m
** Last update Sat May 24 11:54:01 2014 menigo_m
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

char		*get_word(char *str, int *index, int star)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  while (*index >= 0 && (str[*index] == ' ' || str[*index] == '\t'))
    *index = *index - 1;
  while (*index - i >= 0 && str[*index - i] != ' ' && str[*index - i] != '\t')
    i = i + 1;
  i = i - 1;
  if ((tmp = xmalloc(sizeof(char) * (i + 3 - star))) == NULL)
    return (NULL);
  j = 0;
  while (*index - i <= *index && str[*index - i] != '\0' &&
	 str[*index - i] != ' ' && str[*index - i] != '\t')
    tmp[j++] = str[*index - i--];
  if (star == 0)
    {
      tmp[j] = '*';
      tmp[j + 1] = '\0';
    }
  else
    tmp[j] = '\0';
  return (tmp);
}

static char	*get_new_word(t_bin *bin)
{
  int		size;
  char		*word;
  int		i;

  size = get_new_size(bin);
  if ((word = xmalloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      word[i] = bin->next->name[i];
      i = i + 1;
    }
  word[i] = '\0';
  return (word);
}

static char	*autocomplete_replace(char *str, t_bin *bin,
				      int *index, t_cmd *cmd)
{
  char		*new_word;

  if ((new_word = get_new_word(bin)) != NULL)
    {
      if (*index != 0 && is_alpha(str[*index - 1]) == 1)
	str = gere_alt_back(index, str, cmd);
      str = put_in_str(str, *index, new_word);
      free(new_word);
    }
  return (str);
}

void		replace_index(char *str, t_cmd *cmd, t_bin *bin, int *index)
{
  *index = my_strlen(str);
  prompt(cmd);
  my_putstr(str);
  free_final_bin(bin);
}

char		*autocomplete(int *index, char *str, t_cmd *cmd)
{
  int		star;
  t_bin		*bin;
  int		size;

  if (isatty(0) == 0)
    return (str);
  star = contain_star(&str[*index]);
  if (!(bin = xmalloc(sizeof(*bin))))
    return (str);
  bin->next = NULL;
  if (is_first_word(str, *index) == 1 && str[0] != '.')
    {
      if (auto_binaries(cmd, str, bin) == -1)
	return (str);
    }
  else if (auto_file(str, index, bin, star) == -1)
    return (str);
  size = bin_size(bin);
  print_possibilities_or_not(bin, size);
  while (str[*index] != '\0' && str[*index] != ' ' && str[*index] != '\t')
    *index = *index + 1;
  if ((size > 0 && star == 0) || size == 1)
    str = autocomplete_replace(str, bin, index, cmd);
  replace_index(str, cmd, bin, index);
  return (str);
}
