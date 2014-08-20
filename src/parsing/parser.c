/*
** parser.c for  in /home/dong_n/rendu/42sh/parsing/src
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed May  7 23:29:00 2014 dong_n
** Last update Sat May 24 16:17:09 2014 dong_n
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static char	*get_token_quotes(char *str, int *i)
{
  int		j;
  char		quote;
  char		*token;

  quote = str[*i];
  j = ++(*i);
  while (str[j] && str[j] != quote)
    j++;
  if (!(token = xmalloc(sizeof(*token) * (j + 1))))
    return (NULL);
  j = 0;
  while (str[*i] && str[(*i)] != quote)
    token[j++] = str[(*i)++];
  token[j] = '\0';
  if (str[*i] != '\0')
    (*i)++;
  return (token);
}

static char	*get_token(char *str, int *i)
{
  int		j;
  char		*token;

  if (str[*i] == '\'' || str[*i] == '"')
    return (get_token_quotes(str, i));
  if (!(token = xmalloc(sizeof(*token) * (my_tokenlen(&str[*i]) + 1))))
    return (NULL);
  j = 0;
  while (str[*i] && !IS_SEP(str[*i]))
    token[j++] = str[(*i)++];
  token[j] = '\0';
  if (str[*i] != '\0')
    (*i)++;
  return (token);
}

static char	**my_put_token(char *str, char **tab, t_parser *parser, int *j)
{
  char		op;

  if (!str[0])
    {
      free(str);
      return (tab);
    }
  if ((op = my_check_operator(str)) != -1)
    {
      if (my_put_in_parser(parser, tab, str) == -1)
	return (NULL);
      *j = 0;
    }
  else
    {
      if (!(tab = realloc(tab, (*j + 2) * sizeof(*tab))))
	return (NULL);
      tab[(*j)++] = str;
      tab[*j] = NULL;
    }
  return (tab);
}

static int	my_put_end(char *str, char **tab, t_parser *parser, int j)
{
  char		*operator;

  if (str && !str[0])
    {
      free(str);
      free(tab);
      free(parser);
      return (-1);
    }
  free(str);
  if (!(operator = my_strdup(";")))
    return (-1);
  if (!j)
    {
      free(operator);
      free(tab);
    }
  else if (j && !(my_put_token(operator, tab, parser, &j)))
    return (-1);
  if (reverse_syntax(parser) == -1)
    return (-1);
  return (0);
}

t_parser	*my_get_parser(char *str)
{
  char		*token;
  char		**tab;
  t_parser	*parser;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!str || !(parser = init_parser()) || !(tab = xcalloc(1, sizeof(*tab))))
    return (NULL);
  while (str[i])
    {
      if (!(token = get_token(str, &i)) ||
	  !(tab = my_put_token(token, tab, parser, &j)))
	return (NULL);
      if (!j && !(tab = xcalloc(1, sizeof(*tab))))
	return (NULL);
    }
  if (my_put_end(str, tab, parser, j) == -1)
    return (NULL);
  return (parser);
}
