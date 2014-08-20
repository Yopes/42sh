/*
** init.c for  in /home/dong_n/rendu/42sh
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May 23 14:32:54 2014 dong_n
** Last update Sun May 25 21:11:11 2014 menigo_m
*/

#include <signal.h>
#include "my.h"
#include "nautilush.h"

static void		my_signal(int signum, t_cmd *cmd)
{
  static t_cmd		*cmd_save = NULL;

  if (!cmd_save)
    cmd_save = cmd;
  if (signum == SIGINT)
    {
      my_putchar('\n');
      if (cmd_save->pid == NULL)
	prompt(cmd_save);
      else
	kill(cmd_save->pid->pid, signum);
    }
}

t_parser	*init_parser(void)
{
  t_parser	*init;

  if (!(init = xmalloc(sizeof(*init))))
    return (NULL);
  init->prev = init;
  init->next = init;
  return (init);
}

t_cmd		*init_cmd(int argc, char **argv, char **envp)
{
  t_cmd		*cmd;

  (void)argc;
  (void)argv;
  if (!(cmd = xmalloc(sizeof(*cmd))))
    return (NULL);
  cmd->fd[0] = 0;
  cmd->fd[1] = 1;
  cmd->fd[2] = 0;
  cmd->line = 1;
  cmd->pid = NULL;
  if (!(cmd->env = char_to_list(envp)))
    return (NULL);
  my_signal(0, cmd);
  if (signal(SIGTSTP, (void (*)(int))my_signal) == SIG_ERR)
    my_put_error("Signal failed\n");
  if (signal(SIGINT, (void (*)(int))my_signal) == SIG_ERR)
    my_put_error("Signal failed\n");
  return (cmd);
}
