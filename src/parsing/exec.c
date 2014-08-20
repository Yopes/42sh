/*
** exec.c for  in /home/dong_n/rendu/42sh
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May 23 14:19:15 2014 dong_n
** Last update Sun May 25 23:12:35 2014 menigo_m
*/

#include "nautilush.h"
#include "my.h"

static int	check_exec(t_cmd *cmd, int op)
{
  int		exit_value;

  if (op != 3)
    {
      if ((exit_value = check_builtins(cmd)) != -2)
	{
	  if (exit_value > 255)
	    return (exit_value);
	  else
	    gere_next_cmd(cmd, exit_value,
			  my_check_operator(cmd->parser->operator));
	}
      else if (exit_value == -2 && assign_function(cmd) == -2)
	return (EXIT_VALUE(-1));
    }
  else if (gere_pipe(cmd) == -2)
    return (EXIT_VALUE(-1));
  return (0);
}

int		check_op(t_cmd *cmd)
{
  int		op;
  int		exit_value;

  cmd->cmdtab = cmd->parser->cmdtab;
  op = my_check_operator(cmd->parser->operator);
  if (op > 3 && op < 8 && (op = gere_redirections(cmd, op)) == -1)
    return (0);
  if ((exit_value = check_exec(cmd, op)) != 0)
    return (exit_value);
  if (op == 1 || op == 8)
    {
      reset_fd(cmd->fd, 0);
      reset_fd(cmd->fd, 1);
      cmd->parser = cmd->parser->next;
    }
  return (0);
}
