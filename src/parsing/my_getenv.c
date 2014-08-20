/*
** get_env.c for 42sh in /home/abraha_c/rendu/42sh/src/env_tools
** 
** Made by abraha_c
** Login   <abraha_c@epitech.net>
** 
** Started on  Thu May  8 13:51:38 2014 abraha_c
** Last update Sat May 24 12:05:27 2014 menigo_m
*/

#include "my.h"
#include "nautilush.h"

char		*my_getenv(char *str, t_env *env)
{
  t_env		*tmp;

  tmp = env->next;
  while (str && tmp != env)
    {
      if (my_strcmp(tmp->key, str) == 0)
	return (tmp->value);
      tmp = tmp->next;
    }
  return (NULL);
}
