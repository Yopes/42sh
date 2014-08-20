/*
** my_env_var.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Fri May  9 18:56:15 2014 menigo_m
** Last update Sat May 24 15:41:37 2014 dong_n
*/

#include <stdlib.h>
#include <string.h>
#include "nautilush.h"
#include "my.h"

static char	*my_get_key(char *str)
{
  int		i;
  char		*key;

  i = 0;
  while ((str[i] > 64 && str[i] < 91) ||
	 (str[i] > 96 && str[i] < 123) ||
	 (str[i] > 47 && str[i] < 58))
    ++i;
  if (!(key = xmalloc(sizeof(*key) * (i + 1))))
    return (NULL);
  i = 0;
  while ((str[i] > 64 && str[i] < 91) ||
	 (str[i] > 96 && str[i] < 123) ||
	 (str[i] > 47 && str[i] < 58))
    {
      key[i] = str[i];
      ++i;
    }
  key[i] = '\0';
  return (key);
}

static int	replace_env_var(t_parser *tmp, int i, int k, t_env *env)
{
  char		*newarg;
  char		*key;
  char		*value;

  if (!(key = my_get_key(&(tmp->cmdtab[i][k + 1]))) ||
      !(value = my_getenv(key, env)))
    return (-1);
  if (!(newarg = xmalloc(sizeof(*newarg) *
			 (my_strlen(tmp->cmdtab[i]) - my_strlen(key) +
			  my_strlen(value) + 1))))
    return (-1);
  my_strncpy(newarg, tmp->cmdtab[i], k);
  if (!(newarg = my_strcat(newarg, value)))
    return (-1);
  k += my_strlen(key) + 1;
  if (!(newarg = my_strcat(newarg, &(tmp->cmdtab[i][k]))))
    return (-1);
  free(key);
  free(tmp->cmdtab[i]);
  tmp->cmdtab[i] = newarg;
  return (0);
}

static int	replace_var(t_parser *tmp, int i, t_env *env)
{
  int		k;

  k = 0;
  while (tmp->cmdtab[i][k])
    {
      if (tmp->cmdtab[i][k] == '$' &&
	  replace_env_var(tmp, i, k, env) == -1)
	return (-1);
      k++;
    }
  return (0);
}

static int	replace_home(t_parser *tmp, int i, t_env *env)
{
  char		*home;

  if (tmp->cmdtab[i][0] == '~')
    {
      home = my_getenv("HOME", env);
      if (!(home = my_strdup(home)))
	return (-1);
      if (!(home = realloc(home, sizeof(*home) *
			   (my_strlen(home) + my_strlen(tmp->cmdtab[i])))))
	return (-1);
      if (!(home = my_strcat(home, &(tmp->cmdtab[i][1]))))
	return (-1);
      free(tmp->cmdtab[i]);
      tmp->cmdtab[i] = home;
    }
  return (0);
}

int		my_env_var(t_parser *parser, t_env *env)
{
  t_parser	*tmp;
  int		i;

  tmp = parser->next;
  while (tmp != parser)
    {
      i = 0;
      while (tmp->cmdtab[i] != NULL)
	{
	  if (replace_var(tmp, i, env) == -1 ||
	      replace_home(tmp, i, env) == -1)
	    return (-1);
	  i = i + 1;
	}
      tmp = tmp->next;
    }
  return (0);
}
