/*
** my_env.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Mon May 12 15:15:58 2014 menigo_m
** Last update Sat May 17 14:41:06 2014 dong_n
*/

#include "my.h"
#include "nautilush.h"

int		my_env(t_cmd *cmd)
{
  t_env		*tmp;

  tmp = cmd->env->next;
  while (tmp != cmd->env)
    {
      my_putstr_fd(tmp->key, cmd->fd[1]);
      my_putchar_fd('=', cmd->fd[1]);
      my_putstr_fd(tmp->value, cmd->fd[1]);
      my_putchar_fd('\n', cmd->fd[1]);
      tmp = tmp->next;
    }
  return (0);
}
