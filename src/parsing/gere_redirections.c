/*
** gere_redirections.c for  in /home/dong_n/rendu/PSU_2013_42sh/src
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May  9 15:30:27 2014 dong_n
** Last update Sun May 25 22:41:49 2014 menigo_m
*/

#include <stdlib.h>
#include <fcntl.h>
#include "nautilush.h"
#include "my.h"

static const t_redir	g_redirections[] =
  {
    {4, &double_left},
    {5, &simple_left},
    {6, &double_right},
    {7, &simple_right}
  };

int		double_left(t_cmd *cmd)
{
  char		*entry;

  reset_fd(cmd->fd, 0);
  if ((cmd->fd[0] = open(".nautiluSH_tmp", O_WRONLY | O_CREAT | O_TRUNC,
			 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (my_put_error("Open failed\n"));
  my_putstr("> ");
  while ((entry = get_next_line(0)))
    {
      if (!my_strcmp(entry, cmd->parser->next->cmdtab[0]) || check_eot(entry))
	{
	  free(entry);
	  break ;
	}
      write(cmd->fd[0] , entry, my_strlen(entry));
      write(cmd->fd[0] , "\n", 1);
      free(entry);
      my_putstr("> ");
    }
  if (close(cmd->fd[0]) == -1)
    return (-1);
  if ((cmd->fd[0] = open(".nautiluSH_tmp", O_RDONLY)) < 0)
    return (my_put_error("Open failed\n"));
  return (0);
}

int		simple_left(t_cmd *cmd)
{
  int		fd;

  reset_fd(cmd->fd, 0);
  if ((fd = open(cmd->parser->next->cmdtab[0], O_RDONLY)) < 0)
    return (my_put_error("open failed\n"));
  cmd->fd[0] = fd;
  return (0);
}

int		double_right(t_cmd *cmd)
{
  int		fd;

  reset_fd(cmd->fd, 1);
  if ((fd = open(cmd->parser->next->cmdtab[0], O_WRONLY | O_CREAT | O_APPEND,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (my_put_error("Open failed\n"));
  cmd->fd[1] = fd;
  return (0);
}

int		simple_right(t_cmd *cmd)
{
  int		fd;

  reset_fd(cmd->fd, 1);
  if ((fd = open(cmd->parser->next->cmdtab[0], O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (my_put_error("Open failed\n"));
  cmd->fd[1] = fd;
  return (0);
}

int		gere_redirections(t_cmd *cmd, int op)
{
  while (op > 3 && op < 8)
    {
      if (g_redirections[op - 4].func(cmd) == -1)
	{
	  cmd->parser = cmd->parser->next;
	  return (-1);
	}
      cmd->parser = cmd->parser->next;
      op = my_check_operator(cmd->parser->operator);
    }
  return (op);
}
