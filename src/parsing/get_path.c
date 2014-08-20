/*
** get_path.c for  in /home/dong_n/rendu/42sh
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May 15 18:54:26 2014 dong_n
** Last update Sat May 24 12:54:44 2014 menigo_m
*/

#include <string.h>
#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

int		cmd_not_found(char *path, char **paths, char **cmdtab)
{
  my_put_error(cmdtab[0]);
  my_put_error(" : Command not found\n");
  free(path);
  my_freetab(paths);
  free(paths);
  return (-1);
}

char		**my_get_paths(t_env *env)
{
  char		*paths;
  char		**path;

  if (!(paths = my_getenv("PATH", env)))
    return (NULL);
  if (!(path = my_path_to_tab(paths)))
    {
      my_put_error("Failed to get path in tab");
      return (NULL);
    }
  return (path);
}

static char	*my_get_cmd_path(char *dirpath, char *name)
{
  char		*path;
  int		i;
  int		k;

  if (!name)
    return (NULL);
  path = xmalloc((my_strlen(dirpath) + my_strlen(name) + 2) * sizeof(*path));
  if (!path)
    return (NULL);
  i = -1;
  while (dirpath[++i] != '\0')
    path[i] = dirpath[i];
  path[i++] = '/';
  k = 0;
  while (name[k] != '\0')
    path[i++] = name[k++];
  path[i] = '\0';
  return (path);
}

char		*my_check_path(char **paths, char **cmdtab)
{
  int		i;
  char		*path;

  if (!paths)
    return (cmdtab[0]);
  i = 0;
  if (!(path = my_get_cmd_path(paths[i], cmdtab[0])))
    return (NULL);
  while (access(path, X_OK) == -1 && paths[++i])
    {
      free(path);
      if (!(path = my_get_cmd_path(paths[i], cmdtab[0])))
	return (NULL);
    }
  if (!paths[i] && cmd_not_found(path, paths, cmdtab) == -1)
    return (NULL);
  free(cmdtab[0]);
  return (path);
}

int		my_find_cmd(char **paths, char **cmdtab)
{
  if (!(cmdtab && (cmdtab[0][0] == '/' || !strncmp(cmdtab[0], "./", 2))) &&
      !(cmdtab[0] = my_check_path(paths, cmdtab)))
    return (-1);
  if (paths)
    {
      my_freetab(paths);
      free(paths);
    }
  return (0);
}
