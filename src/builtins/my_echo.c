/*
** my_echo.c for  in /home/dong_n/rendu/42sh/src/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May 23 23:45:44 2014 dong_n
** Last update Sun May 25 21:08:30 2014 menigo_m
*/

#include "nautilush.h"
#include "my.h"

static void	my_echo_str(char *str, int fd)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\\')
	my_putchar_fd(str[i], fd);
      i = i + 1;
    }
}

static int	my_echo_n(t_cmd *cmd)
{
  int		i;

  i = 2;
  while (cmd->cmdtab[i])
    {
      my_echo_str(cmd->cmdtab[i], cmd->fd[1]);
      i = i + 1;
      if (cmd->cmdtab[i])
	my_putchar_fd(' ', cmd->fd[1]);
    }
  return (0);
}

int		my_echo(t_cmd *cmd)
{
  int		i;

  i = 1;
  if (cmd->cmdtab[1] && my_strcmp(cmd->cmdtab[1], "-n") == 0)
    my_echo_n(cmd);
  else
    {
      while (cmd->cmdtab[i])
	{
	  my_echo_str(cmd->cmdtab[i], cmd->fd[1]);
	  i = i + 1;
	  if (cmd->cmdtab[i])
	    my_putchar_fd(' ', cmd->fd[1]);
	}
      my_putchar_fd('\n', cmd->fd[1]);
    }
  return (0);
}
