/*
** exec_in_pipe.c for  in /home/dong_n/rendu/PSU_2013_42sh/src
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed May 14 10:35:16 2014 dong_n
** Last update Sun May 25 20:55:39 2014 menigo_m
*/

#include "nautilush.h"
#include "my.h"

static int	exec_in_pipe(t_cmd *cmd)
{
  pid_t		pid;

  if ((pid = xfork()) == -1)
    return (-1);
  if (!(cmd->pid = my_put_pid_in_list(cmd->pid, pid)))
    return (-2);
  if (pid == 0)
    {
      setsid();
      reset_fd(cmd->fd, 0);
      if (cmd->fd[2] != 0)
	cmd->fd[0] = cmd->fd[2];
      if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
	{
	  my_put_error("Dup2 failed\n");
	  return (-2);
	}
      if (check_builtins(cmd) == -2 && exec_function(cmd) == -1)
	return (-2);
      return (-2);
    }
  return (0);
}

static int	set_fd(t_cmd *cmd)
{
  int		save_fd;

  save_fd = 0;
  if (cmd->fd[0] != 0)
    cmd->fd[2] = cmd->fd[0];
  if (cmd->fd[1] != 1)
    save_fd = cmd->fd[1];
  if (pipe(cmd->fd) == -1)
    {
      cmd->parser = cmd->parser->next;
      return (my_put_error("Pipe failed\n"));
    }
  return (save_fd);
}

int		gere_pipe(t_cmd *cmd)
{
  int		save_fd;

  if ((save_fd = set_fd(cmd)) == -1)
    return (-1);
  if (save_fd != 0)
    {
      if (close(cmd->fd[1]) == -1)
	my_put_error("Close failed\n");
      cmd->fd[1] = save_fd;
    }
  if (exec_in_pipe(cmd) == -2)
    return (-2);
  if (cmd->fd[2] != 0 && close(cmd->fd[2]) == -1)
    my_put_error("Close failed\n");
  cmd->fd[2] = 0;
  reset_fd(cmd->fd, 1);
  cmd->parser = cmd->parser->next;
  return (0);
}
