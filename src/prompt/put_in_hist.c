/*
** put_in_hist.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/42sh/src/prompt
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Fri May 16 19:05:49 2014 menigo_m
** Last update Sat May 24 11:54:34 2014 menigo_m
*/

#include "my.h"
#include "nautilush.h"

int		my_put_in_list_rev(t_hist *hist, char *data)
{
  t_hist	*element;

  if (my_strcmp(hist->prev->data, data) == 0)
    return (0);
  element = xmalloc(sizeof(*element));
  if (element == NULL)
    return (-1);
  element->data = xmalloc(sizeof(char) * (my_strlen(data) + 1));
  if (element->data == NULL)
    return (-1);
  element->hist_elem = 0;
  element->data = my_histcpy(element->data, data);
  element->next = hist;
  element->prev = hist->prev;
  hist->prev->next = element;
  hist->prev = element;
  return (0);
}

int		my_put_in_list(t_hist *hist, char *data)
{
  t_hist	*element;

  element = xmalloc(sizeof(*element));
  if (element == NULL)
    return (-1);
  element->data = xmalloc(sizeof(char) * (my_strlen(data) + 1));
  if (element->data == NULL)
    return (-1);
  element->data = my_histcpy(element->data, data);
  element->hist_elem = 0;
  element->prev = hist;
  element->next = hist->next;
  hist->next->prev = element;
  hist->next = element;
  return (0);
}
