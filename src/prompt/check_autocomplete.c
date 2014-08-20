/*
** check_autocomplete.c for 42sh in /home/menigo_m/rendu/42sh/src/prompt
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Mon May 19 13:42:59 2014 menigo_m
** Last update Sun May 25 20:15:14 2014 menigo_m
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

int		isnt_in_bin(char *str, t_bin *bin)
{
  t_bin		*tmp;

  tmp = bin->next;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

int	is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') || c == '*' ||
      (c >= '0' && c <= '9') || c == '-' ||
      c == '_' || c == '.' || c == '/')
    return (1);
  return (0);
}

int	is_first_word(char *str, int index)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\t' && is_alpha(str[i]) == 1)
    i = i + 1;
  if (index <= i)
    return (1);
  return (0);
}

int		auto_file(char *str, int *index, t_bin *bin, int star)
{
  glob_t	pglob;
  char		*tmp;
  int		i;
  int		ret;

  if ((tmp = get_word(str, index, star)) == NULL)
    return (-1);
  ret = glob(tmp, GLOB_ERR | GLOB_TILDE | GLOB_MARK, NULL, &pglob);
  if (ret == GLOB_NOSPACE)
    return (my_put_error("Glob failed\n"));
  if (ret == GLOB_NOMATCH || ret == GLOB_ABORTED)
    return (0);
  free(tmp);
  i = 0;
  while (i < (int)pglob.gl_pathc)
    {
      put_in_bin(bin, pglob.gl_pathv[i]);
      i = i + 1;
    }
  return (0);
}
