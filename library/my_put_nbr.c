/*
** my_put_nbr.c for library in /home/dong_n/Documents
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed Apr 23 13:06:55 2014 dong_n
** Last update Sat May 17 13:06:29 2014 dong_n
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb == -2147483647 - 1)
    {
      my_putchar('-');
      my_putchar('2');
      nb = 147483648;
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

void	my_put_nbr_fd(int nb, int fd)
{
  if (nb == -2147483647 - 1)
    {
      my_putchar_fd('-', fd);
      my_putchar_fd('2', fd);
      nb = 147483648;
    }
  if (nb < 0)
    {
      my_putchar_fd('-', fd);
      nb = -nb;
    }
  if (nb > 9)
    my_put_nbr_fd(nb / 10, fd);
  my_putchar_fd(nb % 10 + '0', fd);
}
