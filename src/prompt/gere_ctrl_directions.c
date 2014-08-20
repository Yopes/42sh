/*
** gere_ctrl_directions.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 11:55:30 2014 menigo_m
** Last update Sat May 17 09:47:12 2014 menigo_m
*/

#include "nautilush.h"

char	*gere_ctrl_right(int *index, char *str, t_cmd *cmd)
{
  while (*index >= 0 && str[*index] != '\0' &&
	 (str[*index] == ' ' || str[*index] == '&'
	  || str[*index] == '|' || str[*index] == ';'
	  || str[*index] == '<' || str[*index] == '>'))
    gere_right(index, str, cmd);
  while (str[*index] != ' ' && str[*index] != '\0'
	 && str[*index] != '&' && str[*index] != '|'
	 && str[*index] != ';' && str[*index] != '<'
	 && str[*index] != '>')
    gere_right(index, str, cmd);
  return (str);
}

char	*gere_ctrl_left(int *index, char *str, t_cmd *cmd)
{
  while (*index > 0 && (str[*index - 1] == ' '
			|| str[*index - 1] == '&' || str[*index - 1] == '|'
			|| str[*index - 1] == ';' || str[*index - 1] == '<'
			|| str[*index - 1] == '>'))
    gere_left(index, str, cmd);
  while (*index > 0 && str[*index - 1] != ' '
	 && str[*index - 1] != '&' && str[*index - 1] != '|'
	 && str[*index - 1] != ';' && str[*index - 1] != '<'
	 && str[*index - 1] != '>')
    gere_left(index, str, cmd);
  return (str);
}
