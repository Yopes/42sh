/*
** get_alias_elem.c for 42sh in /home/menigo_m/rendu/42sh/src/parsing
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 22:34:31 2014 menigo_m
** Last update Fri May 23 22:36:21 2014 menigo_m
*/

#include "nautilush.h"
#include "my.h"

char		*alias_file(t_env *env)
{
  char		*file;
  char		*home;

  home = my_getenv("HOME", env);
  if (home == NULL)
    return (NULL);
  if (!(file = xmalloc(sizeof(char) * (my_strlen("/.nautilurc")
				       + my_strlen(home) + 1))))
    return (NULL);
  my_strcpy(file, home);
  file = my_strcat(file, "/.nautilurc");
  return (file);
}

char		*get_alias_name(char *line)
{
  int		i;
  char		*out;

  i = 0;
  while (line[i] != '\0' && line[i] != '=')
    i = i + 1;
  if (line[i] != '=')
    {
      my_put_error("Invalid alias name\n");
      return (NULL);
    }
  if (!(out = xmalloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = 0;
  while (line[i] != '\0' && line[i] != '=')
    {
      out[i] = line[i];
      i = i + 1;
    }
  out[i] = '\0';
  return (out);
}

char		*get_alias_value(char *line)
{
  char		*value;
  int		i;
  int		y;

  i = 0;
  while (line[i] != '\0' && line[i] != '=')
    i = i + 1;
  i = i + 1;
  y = 0;
  while (line[i] != '\0')
    {
      i = i + 1;
      y = y + 1;
    }
  if (!(value = xmalloc(sizeof(char) * (y + 1))))
    return (NULL);
  i = i - y;
  y = 0;
  while (line[i] != '\0')
    value[y++] = line[i++];
  value[y] = '\0';
  return (value);
}
