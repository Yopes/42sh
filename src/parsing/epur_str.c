/*
** epur_str.c for  in /home/dong_n/rendu/42sh/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May  8 02:21:12 2014 dong_n
** Last update Sat May 24 16:16:09 2014 dong_n
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static void	my_get_quotes(char *str, char *newstr, int *i, int *j)
{
  char		quote;
  char		quote_save;

  quote = str[(*i)++];
  quote_save = 0;
  if (*j == 0 || (*j && newstr[(*j) - 1] != '\'' && newstr[(*j) - 1] != '"'))
    newstr[(*j)++] = quote;
  else if (*j)
    {
      quote_save = newstr[(*j) - 1];
      --(*j);
    }
  while (str[(*i)] && str[(*i)] != quote)
    newstr[(*j)++] = str[(*i)++];
  if (str[(*i)] == quote)
    ++(*i);
  newstr[(*j)++] = EXISTS(quote_save, quote);
  while (IS_SEP(str[*i]))
    ++(*i);
  if (IS_SEP(str[*i - 1]) && str[*i])
    newstr[(*j)++] = ' ';
}

static void	my_get_operande(char *str, char *newstr, int *i, int *j)
{
  char		op;

  op = 0;
  while (str[*i] && !IS_SEP(str[*i]) && !op)
    {
      if (my_check_operator(&str[*i]) != -1)
	op = 1;
      else
	newstr[(*j)++] = str[(*i)++];
    }
  while (IS_SEP(str[*i]))
    ++(*i);
  if (IS_SEP(str[*i - 1]) && str[*i])
    newstr[(*j)++] = ' ';
}
char		*epur_str(char *str)
{
  char		*newstr;
  int		size;
  int		op;
  int		i;
  int		j;

  size = my_cmdlen(str);
  if (!(newstr = xmalloc(sizeof(*newstr) * (size + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (IS_SEP(str[i]))
    i++;
  while (str[i])
    {
      if (str[i] == '"' || str[i] == '\'')
	my_get_quotes(str, newstr, &i, &j);
      else if ((op = my_check_operator(&str[i])) != -1)
      	j += my_get_operator(str, &newstr[j], &i, op);
      else
      	my_get_operande(str, newstr, &i, &j);
    }
  newstr[j] = '\0';
  free(str);
  return (newstr);
}
