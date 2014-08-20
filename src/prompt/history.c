/*
** history.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 13:37:53 2014 menigo_m
** Last update Sat May 24 11:58:38 2014 menigo_m
*/

#include <stdlib.h>
#include <fcntl.h>
#include "nautilush.h"
#include "get_next_line.h"
#include "my.h"

int		save_hist(t_hist *hist, t_env *env)
{
  t_hist	*temp;
  int		fd;
  int		i;
  char		*file;

  i = 0;
  temp = hist->prev;
  if ((file = hist_file(env)) == NULL)
    return (-1);
  if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (my_put_error("Open of .history failed\n"));
  free(file);
  while (temp != hist && i < 1000)
    {
      if (is_empty(temp->data) == 0)
	{
	  write(fd, temp->data, my_strlen(temp->data));
	  write(fd, "\n", 1);
	}
      temp = temp->prev;
      i = i + 1;
    }
  close (fd);
  return (0);
}

t_hist		*init_history(void)
{
  t_hist	*hist;

  hist = xcalloc(1, sizeof(*hist));
  if (hist == NULL)
    return (NULL);
  hist->prev = hist;
  hist->data = NULL;
  hist->next = hist;
  return (hist);
}

static int	get_history_line(int fd, t_hist *hist)
{
  char		*tmp;

  while ((tmp = get_next_line(fd)) != NULL)
    {
      if (is_empty(tmp) == 0)
	{
	  if (my_put_in_list(hist, tmp) == -1)
	    return (-1);
	}
      else
      	free(tmp);
    }
  return (0);
}

t_hist		*get_history(t_env *env)
{
  t_hist	*hist;
  int		fd;
  char		*file;

  if ((hist = init_history()) == NULL)
    return (NULL);
  file = hist_file(env);
  if (file == NULL)
    return (hist);
  fd = open(file, O_RDONLY);
  free(file);
  if (fd <= 0)
    return (hist);
  if (get_history_line(fd, hist) == -1)
    return (NULL);
  close (fd);
  return (hist);
}
