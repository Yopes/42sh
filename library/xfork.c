/*
** xfork.c for xfork in /home/dong_n/rendu/PSU_2013_minishell2
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Sat Mar  8 14:53:54 2014 dong_n
** Last update Thu May 15 13:18:41 2014 dong_n
*/

#include <unistd.h>
#include "my.h"

pid_t	xfork(void)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      my_put_error("Fork failed : Family is too big. ");
      my_put_error("You should stop forkniker\n");
      return (-1);
    }
  return (pid);
}
