/*
** main.c for  in /home/dong_n/rendu/42sh/src
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May 15 16:36:00 2014 dong_n
** Last update Sun May 25 22:44:12 2014 menigo_m
*/

#include <term.h>
#include "my.h"
#include "nautilush.h"

static int		handle_command_line(t_cmd *cmd)
{
  int			exit_value;

  my_env_var(cmd->parser, cmd->env);
  globing_in_cmd(cmd->parser);
  replace_by_alias(cmd);
  cmd->root = cmd->parser;
  cmd->pid = NULL;
  cmd->parser = cmd->parser->next;
  while (cmd->parser != cmd->root)
    if ((exit_value = check_op(cmd)) > 255)
      return (EXIT_VALUE(exit_value));
  (cmd->line)++;
  free_cmd(cmd);
  return (0);
}

static int		main_loop(t_cmd *cmd, struct termios *save)
{
  char			*str;
  int			exit_value;

  while ((str = gere_prompt(cmd)) != NULL)
    {
      save_hist(cmd->hist, cmd->env);
      str = epur_str(str);
      if (tcsetattr(0, 0, save) == -1)
	return (my_put_error("tcsetattr failed\n"));
      if ((cmd->parser = my_get_parser(str)) &&
	  (exit_value = handle_command_line(cmd)) > 255)
	return (exit_value);
      prompt(cmd);
    }
  my_putchar('\n');
  return (0);
}

static int		file_loop(t_cmd *cmd)
{
  char			*str;
  int			exit_value;

  while ((str = get_next_line(0)) != NULL)
    {
      str = epur_str(str);
      if ((cmd->parser = my_get_parser(str)) &&
	  (exit_value = handle_command_line(cmd)) > 255)
	return (exit_value);
      prompt(cmd);
    }
  my_putchar('\n');
  return (0);
}

int			main(int argc, char **argv, char **envp)
{
  struct termios	save;
  t_cmd			*cmd;
  int			exit_value;
  char			*term;
  char			no_term;

  no_term = 0;
  if (!(cmd = init_cmd(argc, argv, envp)) ||
      !(cmd->hist = get_history(cmd->env)) ||
      !(cmd->alias = get_alias(cmd->env)))
    return (-1);
  if (!(term = my_getenv("TERM", cmd->env)) || tgetent(NULL, term) != 1)
    no_term = my_put_error("tgetent failed\n");
  prompt(cmd);
  if (isatty(0) == 0 || tcgetattr(0, &save) == -1 || no_term == -1)
    exit_value = file_loop(cmd);
  else
    {
      exit_value = main_loop(cmd, &save);
      tcsetattr(0, 0, &save);
    }
  reset_fd(cmd->fd, 0);
  reset_fd(cmd->fd, 1);
  free_env(cmd->env);
  return (exit_value);
}
