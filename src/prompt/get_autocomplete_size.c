/*
** get_autocomplete_size.c for  in /home/dong_n/rendu/42sh/src/prompt
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Sat May 24 00:34:20 2014 dong_n
** Last update Sat May 24 11:58:30 2014 menigo_m
*/

#include <glob.h>
#include "nautilush.h"
#include "my.h"

int		get_little_size(t_bin *bin)
{
  int		i;
  int		little_size;
  t_bin		*tmp;

  tmp = bin->next;
  i = 0;
  little_size = my_strlen(tmp->name);
  while (tmp != NULL)
    {
      if (my_strlen(tmp->name) < little_size)
	little_size = my_strlen(tmp->name);
      i = i + 1;
      tmp = tmp->next;
    }
  return (little_size);
}

int		get_new_size(t_bin *bin)
{
  int		i;
  int		little_size;
  t_bin		*tmp;

  i = 0;
  little_size = get_little_size(bin);
  while (i < little_size)
    {
      tmp = bin->next;
      while (tmp != NULL && tmp->next != NULL)
	{
	  if (tmp->name[i] != tmp->next->name[i])
	    return (i);
	  tmp = tmp->next;
	}
      i = i + 1;
    }
  return (i);
}
