/*
** disp_prompt.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Sun May 25 19:19:35 2014 menigo_m
** Last update Sun May 25 19:20:30 2014 menigo_m
*/

#include "my.h"
#include "nautilush.h"

int		prompt(t_cmd *cmd)
{
  char		*username;

  username = my_getenv("USER", cmd->env);
  my_putstr("\033[33m");
  if (username != NULL)
    my_putstr(username);
  else
    my_putstr("login");
  my_putstr("\033[0m");
  my_putchar(' ');
  my_putchar('-');
  my_putchar(' ');
  my_put_nbr(cmd->line);
  my_putchar(' ');
  my_putstr("$> ");
  return (0);
}
