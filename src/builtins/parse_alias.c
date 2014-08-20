/*
** parse_alias.c for 42sh in /home/lopes_n/42sh/src/parsing
**
** Made by lopes_n
** Login   <lopes_n@epitech.net>
**
** Started on  Fri May 23 10:40:43 2014 lopes_n
** Last update Sat May 24 12:06:22 2014 menigo_m
*/

#include "my.h"

static int	nbr_word(char *str)
{
  int		out;
  int		i;
  char		sep;

  i = 0;
  out = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '"' || str[i] == 39)
	i = i + 1;
      else
	{
	  out = out + 1;
	  if (i > 0 && (str[i - 1] == '"' || str[i - 1] == 39))
	    {
	      sep = str[i - 1];
	      while (str[i] != '\n' && str[i] != sep && str[i] != '\0')
		i = i + 1;
	    }
	  else
	    while (str[i] != '\n' && str[i] != ' ' && str[i] != '\0')
	      i = i + 1;
	}
    }
  return (out);
}

static int	malloc_word(char *str, int i)
{
  int		j;
  char		sep;

  j = 1;
  i = i + 1;
  if (i > 1 && (str[i - 1] != '"' || str[i - 1] != 39))
    {
      sep = str[i - 2];
      while (str[i] != sep && str[i] != '\0' && str[i] != '\n')
	{
	  i = i + 1;
	  j = j + 1;
	}
    }
  else
    while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
      {
	i = i + 1;
	j = j + 1;
      }
  return (j + 1);
}

static void	put_nbr_in_tab(int *y, int *i, char *str, char **output)
{
  int		z;

  z = 0;
  output[*y][z] = str[*i];
  *i = *i + 1;
  z = z + 1;
  while (str[*i] != ' ' && str[*i] != '\0' && str[*i] != '\n')
    {
      output[*y][z] = str[*i];
      *i = *i + 1;
      z = z + 1;
    }
  output[*y][z] = '\0';
  *y = *y + 1;
}

static void	put_quote_in_tab(int *y, int *i, char *str, char **output)
{
  int		z;
  char		sep;

  z = 0;
  output[*y][z] = str[*i];
  *i = *i + 1;
  z = z + 1;
  sep = str[(*i) - 2];
  while (str[*i] != sep && str[*i] != '\0' && str[*i] != '\n')
    {
      output[*y][z] = str[*i];
      *i = *i + 1;
      z = z + 1;
    }
  output[*y][z] = '\0';
  *y = *y + 1;
}

char	**parse_alias(char *str)
{
  int	i;
  int	y;
  char	**output;

  output = xmalloc(sizeof(char *) * (nbr_word(str) + 1));
  if (output == NULL)
    return (NULL);
  y = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '"' || str[i] == 39)
	i = i + 1;
      else
	{
	  if ((output[y] = xmalloc(sizeof(char) * malloc_word(str, i))) == NULL)
	    return (NULL);
	  if (i > 0 && (str[i - 1] == '"' || str[i - 1] == 39))
	    put_quote_in_tab(&y, &i, str, output);
	  else
	    put_nbr_in_tab(&y, &i, str, output);
	}
    }
  output[y] = '\0';
  return (output);
}
