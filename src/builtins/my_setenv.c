/*
** unsetenv_42sh.c for 42sh in /home/auduri_a/Desktop/fct_env
** 
** Made by auduri_a
** Login   <auduri_a@epitech.net>
** 
** Started on  Tue May  6 17:10:42 2014 auduri_a
** Last update Sat May 24 12:09:23 2014 menigo_m
*/

#include <stdlib.h>
#include "my.h"
#include "nautilush.h"

static int	put_elem_in_env(t_env *env, char *key, char *value)
{
  t_env		*elem;

  if (!(elem = xmalloc(sizeof(*elem))))
    return (-1);
  if (!(elem->key = my_strdup(key)))
    return (-1);
  if (value && !(elem->value = my_strdup(value)))
    return (-1);
  if (!value)
    elem->value = my_strdup("");
  elem->prev = env->prev;
  elem->next = env;
  env->prev->next = elem;
  env->prev = elem;
  return (0);
}

int		my_setenv_key_value(t_env *env, char *key, char *value)
{
  t_env		*tmp;

  tmp = env->next;
  while (tmp != env)
    {
      if (key && value && my_strcmp(key, tmp->key) == 0)
	{
	  if (tmp->value != NULL)
	    free(tmp->value);
	  if ((tmp->value = my_strdup(value)) == NULL)
	    return (-1);
	  return (0);
	}
      tmp = tmp->next;
    }
  if (key && value)
    return (put_elem_in_env(env, key, value));
  return (-1);
}

int		my_setenv(t_cmd *cmd)
{
  t_env		*tmp;

  tmp = cmd->env->next;
  while (tmp != cmd->env)
    {
      if (cmd->cmdtab[1] &&
	  my_strcmp(cmd->cmdtab[1], tmp->key) == 0)
	{
	  free(tmp->value);
	  if ((tmp->value = my_strdup(cmd->cmdtab[2])) == NULL)
	    return (-1);
	  return (0);
	}
      tmp = tmp->next;
    }
  if (cmd->cmdtab[1])
    return (put_elem_in_env(cmd->env, cmd->cmdtab[1], cmd->cmdtab[2]));
  my_put_error("Usage : my_setenv [key] [value]\n");
  return (-1);
}
