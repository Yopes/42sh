/*
** my_unalias.c for 42sh in /home/menigo_m/rendu/42sh/src/parsing
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Thu May 22 11:54:51 2014 menigo_m
** Last update Sat May 24 12:08:19 2014 menigo_m
*/

#include <stdlib.h>
#include "my.h"
#include "nautilush.h"

int		my_unalias(t_cmd *cmd)
{
  t_alias	*tmp;

  tmp = cmd->alias->next;
  while (tmp != cmd->alias)
    {
      if (my_strcmp(tmp->alias, cmd->cmdtab[1]) == 0)
	{
	  tmp->prev->next = tmp->next;
	  tmp->next->prev = tmp->prev;
	  free(tmp);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (my_put_error("Alias not found\n"));
}
