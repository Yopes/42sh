/*
** init_fcts.c for 42sh in /home/menigo_m/rendu/42sh/src/prompt
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 11:25:05 2014 menigo_m
** Last update Sun May 25 20:29:15 2014 dong_n
*/

#include <stdlib.h>
#include <term.h>
#include "my.h"

static int		init_term(void)
{
  struct termios	term;

  if (tcgetattr(0, &term) == -1)
    return (-1);
  term.c_lflag &= ~ICANON;
  term.c_lflag &= ~ECHO;
  if (tcsetattr(0, 0, &term) == -1)
    return (-1);
  return (0);
}

char		*init_str(int *index)
{
  char		*str;

  if ((str = xmalloc(sizeof(*str) * 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  *index = 0;
  if (init_term() == -1)
    return (NULL);
  return (str);
}
