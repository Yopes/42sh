/*
** autocomplete_binaries.c for  in /home/dong_n/rendu/42sh/src/prompt
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Sat May 24 00:33:17 2014 dong_n
** Last update Sun May 25 20:20:49 2014 menigo_m
*/

#include <stdlib.h>
#include "my.h"
#include "nautilush.h"

static char	*ret_bin_name(char *str)
{
  int		i;
  int		j;
  char		*name;

  i = 0;
  while (str[i])
    i = i + 1;
  while (str[i] != '/' && i > 0)
    i = i - 1;
  if (!(name = xmalloc(sizeof(char) * (my_strlen(str) - i))))
    return (NULL);
  i = i + 1;
  j = 0;
  while (str[i])
    name[j++] = str[i++];
  name[j] = '\0';
  return (name);
}

static char	*create_path(char *path, char *str)
{
  char		*out;

  if (!(out = realloc(path, sizeof(char) * (my_strlen(path)
					    + my_strlen(str) + 3))))
    return (NULL);
  out = my_strcat(out, "/");
  out = my_strcat(out, str);
  out = my_strcat(out, "*");
  return (out);
}

static int	get_in_path(char *path, t_bin *bin, char *str)
{
  glob_t	pglob;
  int		i;
  char		*tmp;
  int		ret;

  if (!(path = create_path(path, str)))
    return (-1);
  ret = glob(path, GLOB_ERR | GLOB_TILDE | GLOB_MARK, NULL, &pglob);
  if (ret == GLOB_NOSPACE)
    return (my_put_error("Glob failed\n"));
  if (ret == GLOB_NOMATCH || ret == GLOB_ABORTED)
    return (0);
  i = 0;
  while (i < (int)pglob.gl_pathc)
    {
      if (!(tmp = ret_bin_name(pglob.gl_pathv[i])))
	return (-1);
      if (isnt_in_bin(tmp, bin) == 1)
	put_in_bin(bin, tmp);
      free(tmp);
      i = i + 1;
    }
  return (0);
}

static char	*get_new_str(char *str)
{
  char		*out;
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\t' && is_alpha(str[i]) == 1)
    i = i + 1;
  if (!(out = xmalloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = 0;
  while (str[i] != '\0' && str[i] != '\t' && is_alpha(str[i]) == 1)
    {
      out[i] = str[i];
      i = i + 1;
    }
  out[i] = '\0';
  return (out);
}

int	auto_binaries(t_cmd *cmd, char *line, t_bin *bin)
{
  char	**paths;
  char	*str;
  int	i;
  char	*new_str;

  if (!(new_str = get_new_str(line)))
    return (-1);
  i = 0;
  if ((str = my_getenv("PATH", cmd->env)) == NULL)
    return (my_put_error("Command not found. PATH is missing !\n"));
  if ((paths = my_path_to_tab(str)) == NULL)
    return (-1);
  while (paths[i])
    if (get_in_path(paths[i++], bin, new_str) == -1)
      return (-1);
  free(new_str);
  sort_bin(bin);
  return (0);
}
