/*
** check_eot.c for  in /home/dong_n/rendu/42sh/src/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May 23 23:35:47 2014 dong_n
** Last update Fri May 23 23:58:55 2014 dong_n
*/

#include "my.h"

int	check_eot(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 4 || (str[i] == '^' && str[++i] == 'D'))
	{
	  my_put_error("Exit : End of Transmission");
	  return (1);
	}
      ++i;
    }
  return (0);
}
