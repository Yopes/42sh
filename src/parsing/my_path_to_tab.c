/*
** my_path_to_tab.c for minishell in /home/dong_n/rendu/PSU_2013_minishell2
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Fri Mar  7 20:53:25 2014 dong_n
** Last update Thu May 15 18:33:52 2014 dong_n
*/

#include <stdlib.h>
#include "my.h"

static int	nb_paths(char *str)
{
  int		i;
  int		k;

  i = 0;
  k = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ':')
	k++;
      i++;
    }
  k++;
  return (k);
}

static int	nb_char(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != ':')
    i++;
  return (i);
}

char		**my_path_to_tab(char *str)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  k = 0;
  if (!(tab = xmalloc((nb_paths(str) + 1) * sizeof(*tab))))
    return (NULL);
  while (str[i] != '\0' && k < nb_paths(str))
    {
      j = 0;
      if (!(tab[k] = xmalloc((nb_char(&str[i]) + 1) * sizeof(**tab))))
	return (NULL);
      while (str[i] != ':' && str[i] != '\0')
	tab[k][j++] = str[i++];
      tab[k][j] = '\0';
      if (str[i] != '\0')
	i++;
      k++;
    }
  tab[k] = NULL;
  return (tab);
}
