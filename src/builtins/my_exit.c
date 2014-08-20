/*
** my_exit.c for  in /home/dong_n/rendu/42sh/src/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Fri May 23 23:45:13 2014 dong_n
** Last update Sat May 24 00:00:32 2014 dong_n
*/

#include "nautilush.h"
#include "my.h"

int		my_exit(t_cmd *cmd)
{
  int		exit_value;

  if (cmd->cmdtab[1])
    exit_value = my_getnbr(cmd->cmdtab[1]);
  else
    exit_value = -1;
  return (EXIT_VALUE(exit_value));
}
