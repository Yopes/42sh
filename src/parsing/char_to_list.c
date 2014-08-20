/*
** char_to_list.c for 42sh in /home/menigo_m/rendu/42sh
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 11:29:31 2014 menigo_m
** Last update Sat May 24 12:02:26 2014 menigo_m
*/

#include "my.h"
#include "nautilush.h"

static int	key_size(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != '=')
    i = i + 1;
  return (i);
}

static int	fill_node(t_env *elem, char *str)
{
  int		i;
  int		j;

  if ((elem->key = xmalloc(sizeof(char) * (key_size(str) + 1))) == NULL)
    return (-1);
  if ((elem->value = xmalloc(sizeof(char) *
			     (my_strlen(str) - key_size(str)))) == NULL)
    return (-1);
  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    {
      elem->key[i] = str[i];
      i = i + 1;
    }
  elem->key[i] = '\0';
  i = i + 1;
  j = 0;
  while (str[i] != '\0')
    elem->value[j++] = str[i++];
  elem->value[j] = '\0';
  return (0);
}

static int	add_elem_to_list(t_env *env, char *str)
{
  t_env		*elem;

  if ((elem = xmalloc(sizeof(*elem))) == NULL)
    return (-1);
  if (fill_node(elem, str) == -1)
    return (-1);
  elem->prev = env->prev;
  elem->next = env;
  env->prev->next = elem;
  env->prev = elem;
  return (0);
}

t_env		*char_to_list(char **envp)
{
  t_env		*env;
  int		i;

  i = 0;
  if ((env = xcalloc(1, sizeof(*env))) == NULL)
    return (NULL);
  env->next = env;
  env->prev = env;
  env->key = NULL;
  env->value = NULL;
  while (envp[i])
    {
      if (add_elem_to_list(env, envp[i]) == -1)
	return (NULL);
      i = i + 1;
    }
  return (env);
}
