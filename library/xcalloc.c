/*
** xcalloc.c for  in /home/dong_n/rendu/42sh
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Thu May 15 18:08:02 2014 dong_n
** Last update Thu May 15 18:14:12 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"

void	*xcalloc(size_t nmemb, size_t size)
{
  void	*ptr;

  ptr = calloc(nmemb, size);
  if (ptr)
    return (ptr);
  my_put_error("Error: Calloc failed\n");
  return (NULL);
}
