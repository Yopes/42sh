/*
** gere_next_cmd.c for  in /home/dong_n/rendu/42sh/src/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Sat May 24 00:01:55 2014 dong_n
** Last update Sun May 25 19:27:15 2014 dong_n
*/

#include "nautilush.h"
#include "my.h"

static int	gere_and(t_cmd *cmd, int status)
{
  if (status == 0)
    cmd->parser = cmd->parser->next;
  else
    {
      while (my_strcmp(cmd->parser->operator, ";") != 0 &&
	     my_strcmp(cmd->parser->operator, "||") != 0)
	{
	  if (cmd->parser == cmd->root)
	    return (-1);
	  cmd->parser = cmd->parser->next;
	}
      cmd->parser = cmd->parser->next;
    }
  return (0);
}

static int	gere_or(t_cmd *cmd, int status)
{
  if (status != 0)
    cmd->parser = cmd->parser->next;
  else
    {
      while (my_strcmp(cmd->parser->operator, ";") != 0 &&
	     my_strcmp(cmd->parser->operator, "&&") != 0)
	{
	  if (cmd->parser == cmd->root)
	    return (-1);
	  cmd->parser = cmd->parser->next;
	}
      cmd->parser = cmd->parser->next;
    }
  return (0);
}

int		gere_next_cmd(t_cmd *cmd, int status, int op)
{
  if (op == 0)
    return (gere_and(cmd, status));
  else if (op == 2)
    return (gere_or(cmd, status));
  return (0);
}
