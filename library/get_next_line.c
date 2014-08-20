/*
** get_next_line.c for 42sh in /home/menigo_m/rendu/42sh
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Fri May 23 11:29:28 2014 menigo_m
** Last update Sun May 25 17:52:22 2014 dong_n
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char	*my_realloc(char *ret, int size, int rd)
{
  char	*str;

  ret[size] = '\0';
  if (size == 0)
    return (ret);
  if (!(str = xmalloc((size + rd + 2) * sizeof(*str))))
    return (NULL);
  my_strcpy(str, ret);
  free(ret);
  return (str);
}

char	*ret_next_line(char *ret, int i, int k)
{
  if (i > 0 || k == 1)
    {
      ret = my_realloc(ret, i, 0);
      return (ret);
    }
  free(ret);
  return (NULL);
}

char	*my_verif_read(char *ret, int rd, int i)
{
  if (rd < 0)
    return (NULL);
  ret = my_realloc(ret, i, rd);
  return (ret);
}

char		*get_next_line(const int fd)
{
  static int	rd;
  static int	j = 0;
  static char	buffer[ABS(BUFF_SIZE)];
  int		i;
  char		*ret;

  i = 0;
  if (!(ret = xmalloc((BUFF_SIZE + 1) * sizeof(*ret))))
    return (NULL);
  if (j != 0)
    while (j < rd && buffer[j] != '\n')
      ret[i++] = buffer[j++];
  if (j < rd && buffer[j++] == '\n')
    return (ret_next_line(ret, i, 1));
  while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
    {
      j = 0;
      if (!(ret = my_verif_read(ret, rd, i)))
	return (NULL);
      while (j < rd && buffer[j] != '\n')
	ret[i++] = buffer[j++];
      if ((j < rd && buffer[j++] == '\n') || i == 0 || i > 500)
	return (ret_next_line(ret, i, 1));
    }
  return (ret_next_line(ret, i, 0));
}
