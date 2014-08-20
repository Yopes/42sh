/*
** put_del_str.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 13:37:35 2014 menigo_m
** Last update Sat May 24 11:54:53 2014 menigo_m
*/

#include <stdlib.h>
#include "my.h"

char	*del_in_str(char *str, int index)
{
  int	i;
  char	*tmp;

  if (my_strlen(&str[index - 1]) == 0)
    return (str);
  if ((tmp = xmalloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(tmp, str);
  if ((str = xmalloc(sizeof(char) * (my_strlen(tmp) + 2))) == NULL)
    return (NULL);
  my_strncpy(str, tmp, index);
  i = index - 1;
  while (tmp[index] != '\0')
    str[i++] = tmp[index++];
  str[i] = '\0';
  free(tmp);
  return (str);
}

char	*put_in_str(char *str, int index, char *c)
{
  int	i;
  char	*tmp;
  int	y;

  if ((tmp = xmalloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(tmp, str);
  if ((str = xmalloc(sizeof(char) * (my_strlen(tmp)
				     + my_strlen(c) + 1))) == NULL)
    return (NULL);
  my_strncpy(str, tmp, index);
  y = 0;
  i = index;
  while (c[y] != '\0')
    str[i++] = c[y++];
  while (tmp[index] != '\0')
    {
      str[i] = tmp[index];
      i = i + 1;
      index = index + 1;
    }
  str[i] = '\0';
  free(tmp);
  return (str);
}
