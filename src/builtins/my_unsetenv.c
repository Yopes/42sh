/*
** unsetenv_42sh.c for 42sh in /home/auduri_a/Desktop/fct_env
** 
** Made by auduri_a
** Login   <auduri_a@epitech.net>
** 
** Started on  Tue May  6 17:10:42 2014 auduri_a
** Last update Sat May 24 12:09:17 2014 menigo_m
*/

#include <stdlib.h>
#include "my.h"
#include "nautilush.h"

int		my_unsetenv(t_cmd *cmd)
{
  t_env		*tmp;

  tmp = cmd->env->next;
  while (tmp != cmd->env)
    {
      if (my_strcmp(cmd->cmdtab[1], tmp->key) == 0)
	{
	  tmp->prev->next = tmp->next;
	  tmp->next->prev = tmp->prev;
	  free(tmp);
	  return (0);
	}
      tmp = tmp->next;
    }
  if (cmd->cmdtab[1])
    {
      my_put_error(cmd->cmdtab[1]);
      my_put_error(" : not found\n");
    }
  else
    my_put_error("Usage : unsetenv [key]\n");
  return (-1);
}
