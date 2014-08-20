/*
** history_built_in.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu May  8 09:32:38 2014 menigo_m
** Last update Sat May 24 11:57:19 2014 menigo_m
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "nautilush.h"
#include "my.h"

static char	*get_elem_in_history(t_hist *tmp, char *str, int i, int size)
{
  char		*elem;

  if (&str[1] && tmp->data &&
      strncmp(&str[1], tmp->data, my_strlen(&str[1])) == 0)
    {
      my_putchar('\n');
      my_putstr(tmp->data);
      elem = my_strdup(tmp->data);
      return (elem);
    }
  else if (my_getnbr(&str[1]) > 0 && size - i == my_getnbr(&str[1]))
    {
      my_putchar('\n');
      my_putstr(tmp->data);
      elem = my_strdup(tmp->data);
      return (elem);
    }
  else if (my_getnbr(&str[1]) < 0 && -my_getnbr(&str[1]) == i)
    {
      my_putchar('\n');
      my_putstr(tmp->data);
      elem = my_strdup(tmp->data);
      return (elem);
    }
  return (str);
}

char		*check_last_hist(t_hist *hist, char *str)
{
  t_hist	*tmp;
  int		i;
  int		size;
  char		*temp;

  if (str[0] == '!')
    {
      size = my_list_size(hist) + 1;
      i = 1;
      tmp = hist->prev;
      while (tmp != hist)
	{
	  temp = get_elem_in_history(tmp, str, i, size);
	  if (temp != str)
	    return (temp);
	  i = i + 1;
	  tmp = tmp->prev;
	}
      my_putchar('\n');
      my_put_error(str);
      my_put_error(": event not found\n");
      return (NULL);
    }
  return (str);
}

static int	del_history(t_cmd *cmd)
{
  t_hist	*tmp;
  int		fd;
  char		*file;

  tmp = cmd->hist->prev;
  while (tmp != cmd->hist)
    {
      tmp = tmp->prev;
      delete_in_hist(tmp->next);
    }
  if ((file = hist_file(cmd->env)) == NULL)
    return (-1);
  if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-1);
  free(file);
  close(fd);
  return (0);
}

static void	show_history(t_cmd *cmd)
{
  t_hist	*tmp;
  int		i;

  i = 0;
  tmp = cmd->hist->next;
  while (tmp != cmd->hist)
    {
      my_put_nbr_fd(++i, cmd->fd[1]);
      my_putchar_fd('\t', cmd->fd[1]);
      my_putstr_fd(tmp->data, cmd->fd[1]);
      my_putchar_fd('\n', cmd->fd[1]);
      tmp = tmp->next;
    }
}

int		gere_history(t_cmd *cmd)
{
  if (cmd->cmdtab[1] && my_strcmp(cmd->cmdtab[1], "-c") == 0)
    del_history(cmd);
  else
    show_history(cmd);
  return (0);
}
