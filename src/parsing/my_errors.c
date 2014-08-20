/*
** my_errors.c for  in /home/dong_n/rendu/42sh/src/parsing
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Tue May 20 19:19:03 2014 dong_n
** Last update Tue Jun  3 13:40:06 2014 menigo_m
*/

#include <signal.h>
#include "nautilush.h"
#include "my.h"

static const t_error	g_errors[] = {
  {SIGQUIT, "Quit\n"},
  {SIGILL, "Illegal Instruction\n"},
  {SIGABRT, "Aborted\n"},
  {SIGFPE, "Floating point exception\n"},
  {SIGSEGV, "Segmentation fault\n"}
};

int	my_child_error(int status)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      if (status == g_errors[i].status)
	my_put_error(g_errors[i].msg);
      i++;
    }
  return (-1);
}
