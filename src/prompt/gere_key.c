/*
** gere_key.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Tue May  6 13:37:56 2014 menigo_m
** Last update Sat May 24 11:59:03 2014 menigo_m
*/

#include <stdlib.h>
#include <term.h>
#include "nautilush.h"
#include "my.h"

char	*clear_scr(int *index, char *str, t_cmd *cmd)
{
  char	*cl;

  (void)*index;
  cl = tgetstr("cl", NULL);
  my_putstr(cl);
  prompt(cmd);
  if (str != NULL)
    my_putstr(str);
  return (str);
}

char	*gere_letter(int *index, char *c, char *str)
{
  char	*ei;
  char	*im;

  ei = tgetstr("ei", NULL);
  im = tgetstr("im", NULL);
  my_putstr(im);
  my_putstr(c);
  if ((str = put_in_str(str, *index, c)) == NULL)
    return (NULL);
  *index = *index + my_strlen(c);
  my_putstr(ei);
  return (str);
}
