/*
** list_to_char.c for  in /home/dong_n/rendu/42sh
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Thu May 15 17:09:10 2014 dong_n
** Last update Sat May 24 12:01:28 2014 menigo_m
*/

#include "my.h"
#include "nautilush.h"

static int	count_nb_elem(t_env *env)
{
  t_env		*tmp;
  int		i;

  i = 0;
  tmp = env->next;
  while (tmp != env)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  return (i);
}

static char	*place_in_tab(t_env *tmp)
{
  char		*str;
  int		i;
  int		j;

  j = 0;
  i = 0;
  if ((str = xmalloc(sizeof(char) * (my_strlen(tmp->key)
				     + my_strlen(tmp->value) + 2))) == NULL)
    return (NULL);
  while (tmp->key[i] != '\0')
    str[j++] = tmp->key[i++];
  str[j++] = '=';
  i = 0;
  while (tmp->value[i] != '\0')
    str[j++] = tmp->value[i++];
  str[j] = '\0';
  return (str);
}

char		**list_to_char(t_env *env)
{
  t_env		*tmp;
  char		**out;
  int		i;

  i = 0;
  if ((out = xmalloc(sizeof(char *) * (count_nb_elem(env) + 1))) == NULL)
    return (NULL);
  tmp = env->next;
  while (tmp != env)
    {
      if ((out[i++] = place_in_tab(tmp)) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  out[i] = NULL;
  return (out);
}
