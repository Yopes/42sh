/*
** hist_file.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May 13 13:58:37 2014 menigo_m
** Last update Sat May 24 11:56:39 2014 menigo_m
*/

#include "nautilush.h"
#include "my.h"

char		*hist_file(t_env *env)
{
  char		*file;
  char		*home;

  home = my_getenv("HOME", env);
  if (home == NULL)
    return (NULL);
  if (!(file = xmalloc(sizeof(char) * (my_strlen("/.history")
				       + my_strlen(home) + 1))))
    return (NULL);
  my_strcpy(file, home);
  file = my_strcat(file, "/.history");
  return (file);
}
