/*
** reset_fd.c for  in /home/dong_n/rendu/PSU_2013_42sh/src
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Mon May 12 19:14:20 2014 dong_n
** Last update Mon May 12 19:17:03 2014 dong_n
*/

#include <unistd.h>
#include "my.h"

void	reset_fd(int *fd, int i)
{
  if (fd[i] != i && close(fd[i]) == -1)
    my_put_error("Close failed\n");
  fd[i] = i;
}
