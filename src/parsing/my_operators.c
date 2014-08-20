/*
** my_operators.c for  in /home/dong_n/rendu/42sh/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May  8 00:00:10 2014 dong_n
** Last update Sat May 24 12:05:35 2014 menigo_m
*/

#include <string.h>
#include "nautilush.h"
#include "my.h"

static const char	*g_operator[] =
  {
    "&&",
    "&",
    "||",
    "|",
    "<<",
    "<",
    ">>",
    ">",
    ";"
  };

void	my_operator_len(char *str, int *i, int *size, int op)
{
  int	operator_len;

  operator_len = my_strlen(g_operator[op]);
  if (*i != 0 && !IS_SEP(str[(*i) - 1]))
    ++(*size);
  *i += operator_len;
  *size += operator_len + 1;
  while (IS_SEP(str[*i]))
    ++(*i);
}

int	my_get_operator(char *str, char *newstr, int *i, int op)
{
  int	j;
  int	k;

  j = 0;
  if (*i != 0 && !IS_SEP(str[(*i) - 1]))
    newstr[j++] = ' ';
  k = 0;
  while (g_operator[op][k++])
    newstr[j++] = str[(*i)++];
  newstr[j++] = ' ';
  while (IS_SEP(str[*i]))
    ++(*i);
  return (j);
}

int	my_check_operator(char *str)
{
  int	i;

  if (!str)
    return (-1);
  i = 0;
  while (i < (int)(sizeof(g_operator) / sizeof(*g_operator)))
    {
      if (!strncmp(str, g_operator[i], my_strlen(g_operator[i])))
	return (i);
      i++;
    }
  return (-1);
}
