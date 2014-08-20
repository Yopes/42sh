/*
** gere_history.c for 42sh in /home/lopes_n/rendu/PSU_2013_42sh
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Fri Apr 18 10:51:12 2014 lopes_n
** Last update Sat May 24 11:59:10 2014 menigo_m
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

int		my_list_size(t_hist *hist)
{
  t_hist	*tmp;
  int		i;

  i = 0;
  tmp = hist->next;
  while (tmp != hist)
    {
      i = i + 1;
      tmp = tmp->next;
    }
  return (i);
}

char		*get_elem(int hist_elem, t_hist *hist, int *flag)
{
  t_hist	*temp;
  int		i;
  char		*elem;

  i = 0;
  temp = hist->prev;
  while (temp != hist && temp->data != NULL && i < hist_elem)
    {
      i = i + 1;
      temp = temp->prev;
    }
  if (temp->data == NULL)
    {
      *flag = 1;
      elem = my_strdup(temp->next->data);
      return (elem);
    }
  *flag = 0;
  elem = my_strdup(temp->data);
  return (elem);
}

void		delete_in_hist(t_hist *hist)
{
  hist->prev->next = hist->next;
  hist->next->prev = hist->prev;
  if (hist)
    free(hist);
}

int		epur_hist(t_hist *hist, char flag)
{
  t_hist	*tmp;

  if (flag == 1)
    tmp = hist->prev->prev;
  else
    tmp = hist->prev;
  while (tmp != hist)
    {
      if (tmp->data == NULL || is_empty(tmp->data) == 1)
	{
	  tmp = tmp->prev;
	  delete_in_hist(tmp->next);
	}
      tmp = tmp->prev;
    }
  return (0);
}
