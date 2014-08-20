/*
** reverse_syntax.c for  in /home/dong_n/rendu/42sh/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May  8 14:55:51 2014 dong_n
** Last update Sat May 24 12:05:55 2014 menigo_m
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static int	my_bad_token(char *operator)
{
  my_put_error("nautiluSH: syntax error near unexpected token '");
  my_put_error(operator);
  my_put_error("'\n");
  return (-1);
}

static int	my_replace_tab(t_parser *parser, t_parser *cmd)
{
  int		i;
  int		next_size;
  int		size;

  next_size = my_tablen(parser->cmdtab);
  size = my_tablen(cmd->cmdtab);
  if (next_size > 1)
    {
      if (!(cmd->cmdtab = realloc(cmd->cmdtab, (size + next_size + 1)
				  * sizeof(*(cmd->cmdtab)))))
	return (-1);
      i = 1;
      while (i < next_size && parser->cmdtab[i])
	cmd->cmdtab[size++] = parser->cmdtab[i++];
      cmd->cmdtab[size] = NULL;
      parser->cmdtab[1] = NULL;
    }
  return (0);
}

static int	verify_parser(t_parser *parser)
{
  t_parser	*tmp;

  tmp = parser->next;
  while (tmp != parser)
    {
      if (!(tmp->cmdtab[0]))
	return (my_bad_token(tmp->operator));
      tmp = tmp->next;
    }
  return (0);
}

int		reverse_syntax(t_parser *parser)
{
  t_parser	*tmp;
  t_parser	*cmd;
  int		op;

  tmp = parser->next;
  while (tmp != parser)
    {
      op = my_check_operator(tmp->operator);
      cmd = tmp;
      if (op > 3 && op < 8)
	while (op > 3 && op < 8)
	  {
	    if (tmp->next == parser || my_replace_tab(tmp->next, cmd) == -1)
	      return (my_bad_token(tmp->operator));
	    tmp = tmp->next;
	    op = my_check_operator(tmp->operator);
	  }
      else
	tmp = tmp->next;
    }
  if (verify_parser(parser) == -1)
    return (-1);
  return (0);
}
