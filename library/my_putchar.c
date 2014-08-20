/*
** my_putchar.c for library in /home/dong_n/Documents
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed Apr 23 13:07:37 2014 dong_n
** Last update Sat May 17 12:52:04 2014 dong_n
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}
