/*
** assign_function.c for  in /home/dong_n/rendu/PSU_2013_42sh/src
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Mon May 12 17:21:36 2014 dong_n
** Last update Sun May 25 20:49:34 2014 menigo_m
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "nautilush.h"
#include "my.h"

static int	my_wait(t_cmd *cmd)
{
  int		status;
  int		op;
  t_pid		*tmp;

  reset_fd(cmd->fd, 0);
  tmp = cmd->pid;
  waitpid(cmd->pid->pid, &status, 0);
  my_child_error(status);
  cmd->pid = cmd->pid->next;
  free(tmp);
  while (cmd->pid)
    {
      tmp = cmd->pid;
      waitpid(cmd->pid->pid, &status, 0);
      cmd->pid = cmd->pid->next;
      free(tmp);
    }
  if ((op = my_check_operator(cmd->parser->operator)) == -1)
    return (-1);
  return (gere_next_cmd(cmd, status, op));
}

static int	exec_failed(char *str)
{
  struct stat	exe;

  my_put_error(str);
  if (lstat(str, &exe) == -1)
    my_put_error(": Command not found\n");
  else
    if ((exe.st_mode & S_IFDIR) != 0)
      my_put_error(": is a directory\n");
    else
      my_put_error(": Permission denied\n");
  return (-1);
}

int		exec_function(t_cmd *cmd)
{
  char		**paths;
  char		**env;

  paths = my_get_paths(cmd->env);
  if ((my_find_cmd(paths, cmd->cmdtab) == -1) ||
      !(env = list_to_char(cmd->env)))
    return (-1);
  if (execve(cmd->cmdtab[0], cmd->cmdtab, env) == -1)
    return (exec_failed(cmd->cmdtab[0]));
  return (0);
}

int		assign_function(t_cmd *cmd)
{
  pid_t		pid;

  if ((pid = xfork()) == -1)
    return (-1);
  if (!(cmd->pid = my_put_pid_in_list(cmd->pid, pid)))
    return (-2);
  if (pid == 0)
    {
      setsid();
      if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
	{
	  my_put_error("Dup2 failed\n");
	  return (-2);
	}
      if (exec_function(cmd) == -1)
	return (-2);
    }
  else
    return (my_wait(cmd));
  return (0);
}
