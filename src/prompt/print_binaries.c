/*
** print_binaries.c for 42sh in /home/menigo_m/rendu/42sh/src/prompt
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Wed May 21 12:18:23 2014 menigo_m
** Last update Sun May 25 19:18:06 2014 menigo_m
*/

#include <stdio.h>
#include <term.h>
#include "nautilush.h"
#include "my.h"

int		bin_size(t_bin *bin)
{
  t_bin		*tmp;
  int		i;

  i = 0;
  tmp = bin->next;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  return (i);
}

void		print_possibilities(t_bin *bin)
{
  t_bin		*tmp;

  tmp = bin->next;
  my_putchar(10);
  while (tmp != NULL)
    {
      if (printf("\033[36m%s\033[0m\n", tmp->name) < 0)
	return ;
      tmp = tmp->next;
    }
}

static void	too_many_bin(t_bin *bin, int size)
{
  char		buf[2];
  int		rd;

  buf[0] = 0;
  buf[1] = 0;
  my_putstr("\nDisplay all ");
  my_put_nbr(size);
  my_putstr(" possibilities ? (y or n)");
  while (buf[0] != 'y' && buf[0] != 'n' &&
	 buf[0] != 'Y' && buf[0] != 'N' && (rd = read(0, buf, 1)) > 0)
    {
      if (buf[0] == 'y' || buf[0] == 'Y')
	print_possibilities(bin);
      else if (buf[0] == 'n' || buf[0] == 'N')
	{
	  my_putchar(10);
	  return ;
	}
    }
  if (rd <= 0)
    return ;
}

void		print_possibilities_or_not(t_bin *bin, int size)
{
  char		*dl;
  char		*ch;
  char		*replace;

  if (!(dl = tgetstr("dl", NULL)))
    return ;
  if (!(ch = tgetstr("ch", NULL)))
    return ;
  if (!(replace = tparm(ch, 0)))
    return ;
  if (size == 1)
    {
      my_putstr(dl);
      my_putstr(replace);
      return ;
    }
  else if (size <= 50)
    print_possibilities(bin);
  else
    too_many_bin(bin, size);
}
