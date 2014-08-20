/*
** my_strdup.c for library in /home/dong_n/Documents
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu Apr 24 14:06:30 2014 dong_n
** Last update Tue May 20 11:32:57 2014 lopes_n
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*ret;

  if (!src)
    return (NULL);
  if (!(ret = xmalloc((my_strlen(src) + 1) * sizeof(*ret))))
    return (NULL);
  my_strcpy(ret, src);
  return (ret);
}
