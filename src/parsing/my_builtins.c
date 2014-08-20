/*
** my_builtins.c for  in /home/dong_n/rendu/42sh/src/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May 23 23:43:20 2014 dong_n
** Last update Fri May 23 23:43:56 2014 dong_n
*/

#include "nautilush.h"
#include "my.h"

static const t_built_in	g_built_ins[] =
  {
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"echo", &my_echo},
    {"exit", &my_exit},
    {"env", &my_env},
    {"history", &gere_history},
    {"cd", &change_folder},
    {"alias", &my_alias},
    {"unalias", &my_unalias}
  };

int		check_builtins(t_cmd *cmd)
{
  int		i;
  int		exit_value;

  i = 0;
  while (i < 9)
    {
      if (my_strcmp(g_built_ins[i].cmd, cmd->cmdtab[0]) == 0)
	{
	  exit_value = g_built_ins[i].function(cmd);
	  reset_fd(cmd->fd, 1);
	  return (exit_value);
	}
      ++i;
    }
  return (-2);
}
