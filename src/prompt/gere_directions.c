/*
** gere_directions.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 11:14:50 2014 menigo_m
** Last update Sat May 24 11:59:23 2014 menigo_m
*/

#include <stdlib.h>
#include <term.h>
#include "nautilush.h"
#include "my.h"

char	*gere_left(int *index, char *str, t_cmd *cmd)
{
  char	*le;

  (void)cmd;
  le = tgetstr("le", NULL);
  if (*index > 0)
    {
      *index = *index - 1;
      my_putstr(le);
    }
  return (str);
}

char	*gere_right(int *index, char *str, t_cmd *cmd)
{
  char	*nd;

  (void)cmd;
  nd = tgetstr("nd", NULL);
  if (*index < my_strlen(str))
    {
      *index = *index + 1;
      my_putstr(nd);
    }
  return (str);
}

char	*gere_down(t_cmd *cmd, int *index, int *hist_elem, char *str)
{
  char	*nd;
  int	end;

  if (*hist_elem > 0)
    {
      nd = tgetstr("nd", NULL);
      while (*index < my_strlen(str))
	{
	  *index = *index + 1;
	  my_putstr(nd);
	}
      while (*index > 0)
	gere_back(index, str, cmd);
      str = get_elem(*hist_elem - 1, cmd->hist, &end);
      my_putstr(str);
      *index = my_strlen(str);
      if (end == 0)
	*hist_elem = *hist_elem - 1;
    }
  return (str);
}

char	*gere_up(t_cmd *cmd, int *index, int *hist_elem, char *str)
{
  char	*nd;
  int	start;

  epur_hist(cmd->hist, 1);
  if (*hist_elem == 0)
    my_put_in_list_rev(cmd->hist, str);
  if (*hist_elem < 1000 && *hist_elem < my_list_size(cmd->hist))
    {
      nd = tgetstr("nd", NULL);
      while (*index < my_strlen(str))
	{
	  *index = *index + 1;
	  my_putstr(nd);
	}
      while (*index > 0)
	gere_back(index, str, cmd);
      str = get_elem(*hist_elem + 1, cmd->hist, &start);
      my_putstr(str);
      *index = my_strlen(str);
      if (start == 0)
	*hist_elem = *hist_elem + 1;
    }
  return (str);
}
