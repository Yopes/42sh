/*
** sort_list.c for 42sh in /home/lopes_n/rendu/42shv2
**
** Made by lopes_n
** Login   <lopes_n@epitech.net>
**
** Started on  Sat May 17 17:21:50 2014 lopes_n
** Last update Sat May 24 11:54:18 2014 menigo_m
*/

#include "nautilush.h"
#include "my.h"

static void	find_place(t_bin *next, t_bin *temp,
			   t_bin *output, char *name)
{
  while (next->next != NULL &&
	 my_strcmp(next->name, name) < 0)
    {
      temp = temp->next;
      next = temp->next;
    }
  if (my_strcmp(next->name, name) < 0)
    next->next = output;
  else
    {
      temp->next = output;
      output->next = next;
    }
}

static t_bin	*put_elem(t_bin *bin, char *name)
{
  t_bin		*temp;
  t_bin		*output;
  t_bin		*next;

  if ((output = xmalloc(sizeof(t_bin))) == NULL)
    return (NULL);
  output->name = name;
  output->next = NULL;
  if (bin == NULL)
    return output;
  temp = bin;
  next = temp->next;
  if (my_strcmp(temp->name, name) < 0)
    {
      if (next == NULL)
	temp->next = output;
      else
	find_place(next, temp, output, name);
      return (temp);
    }
  else
    output->next = temp;
  return (output);
}

int		sort_bin(t_bin *bin)
{
  t_bin		*tmp;
  t_bin		*out;

  out = NULL;
  tmp = bin->next;
  while (tmp != NULL)
    {
      out = put_elem(out, tmp->name);
      tmp = tmp->next;
    }
  if (out == NULL)
    return (-1);
  free_bin(bin);
  bin->next = out;
  return (0);
}
