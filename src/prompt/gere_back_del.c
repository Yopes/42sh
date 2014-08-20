/*
** gere_back_del.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 11:56:37 2014 menigo_m
** Last update Tue May 20 15:28:22 2014 menigo_m
*/

#include <stdlib.h>
#include <term.h>
#include "nautilush.h"
#include "my.h"

char	*gere_alt_back(int *index, char *str, t_cmd *cmd)
{
  while (*index > 0 && (str[*index - 1] == ' '
			|| str[*index - 1] == '&' || str[*index - 1] == '|'
			|| str[*index - 1] == ';' || str[*index - 1] == '<'
			|| str[*index - 1] == '>'))
    if ((str = gere_back(index, str, cmd)) == NULL)
      return (NULL);
  while (*index > 0 && str[*index - 1] != ' '
	 && str[*index - 1] != '&' && str[*index - 1] != '|'
	 && str[*index - 1] != ';' && str[*index - 1] != '<'
	 && str[*index - 1] != '>')
    if ((str = gere_back(index, str, cmd)) == NULL)
      return (NULL);
  return (str);
}

char	*gere_back(int *index, char *str, t_cmd *cmd)
{
  char	*dm;
  char	*ed;
  char	*dc;
  char	*le;

  (void)cmd;
  dm = tgetstr("dm", NULL);
  ed = tgetstr("ed", NULL);
  dc = tgetstr("dc", NULL);
  le = tgetstr("le", NULL);
  if (*index > 0)
    {
      my_putstr(le);
      my_putstr(dm);
      my_putstr(dc);
      if ((str = del_in_str(str, *index)) == NULL)
	return (NULL);
      *index = *index - 1;
      my_putstr(ed);
    }
  return (str);
}

char	*gere_del(int *index, char *str, t_cmd *cmd)
{
  char	*dc;

  (void)cmd;
  dc = tgetstr("dc", NULL);
  my_putstr(dc);
  if ((str = del_in_str(str, *index + 1)) == NULL)
    return (NULL);
  return (str);
}
