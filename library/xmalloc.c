/*
** xmalloc.c for library in /home/dong_n/Documents
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed Apr 23 13:06:23 2014 dong_n
** Last update Fri May 16 19:29:51 2014 menigo_m
*/

#include <stdlib.h>
#include "my.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr)
    return (ptr);
  my_put_error("Error: Malloc failed\n");
  return (NULL);
}
