/*
** my_putstr.c for library in /home/dong_n/Documents
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed Apr 23 13:07:51 2014 dong_n
** Last update Sat May 17 09:30:15 2014 dong_n
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putstr_fd(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}

int	my_put_error(char *str)
{
  write(2, "\033[31m", 5);
  write(2, str, my_strlen(str));
  write(2, "\033[0m", 4);
  return (-1);
}
