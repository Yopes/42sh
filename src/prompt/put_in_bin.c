/*
** put_in_bin.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src/prompt
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Sun May 25 20:17:51 2014 menigo_m
** Last update Sun May 25 20:19:09 2014 menigo_m
*/

#include "my.h"
#include "nautilush.h"

int		put_in_bin(t_bin *bin, char *name)
{
  t_bin		*element;
  t_bin		*tmp;

  tmp = bin;
  element = xmalloc(sizeof(*element));
  if (element == NULL)
    return (-1);
  element->name = xmalloc(sizeof(char) * (my_strlen(name) + 1));
  if (element->name == NULL)
    return (-1);
  my_strcpy(element->name, name);
  element->next = NULL;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = element;
  return (0);
}
