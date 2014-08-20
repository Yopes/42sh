/*
** gere_ctrl_letter.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 11:57:38 2014 menigo_m
** Last update Sat May 24 11:59:33 2014 menigo_m
*/

#include <stdlib.h>
#include <term.h>
#include "nautilush.h"
#include "my.h"

char	*gere_ctrl_e(int *index, char *str, t_cmd *cmd)
{
  char	*nd;

  (void)cmd;
  nd = tgetstr("nd", NULL);
  while (*index < my_strlen(str))
    {
      *index = *index + 1;
      my_putstr(nd);
    }
  return (str);
}

char	*gere_ctrl_a(int *index, char *str, t_cmd *cmd)
{
  char	*le;

  (void)cmd;
  le = tgetstr("le", NULL);
  while (*index > 0)
    {
      *index = *index - 1;
      my_putstr(le);
    }
  return (str);
}
