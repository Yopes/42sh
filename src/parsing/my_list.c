/*
** my_list.c for  in /home/dong_n/rendu/42sh/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May  8 01:42:21 2014 dong_n
** Last update Sat May 24 12:01:06 2014 menigo_m
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

t_pid		*my_put_pid_in_list(t_pid *list_pid, pid_t pid)
{
  t_pid		*elem;

  if (!(elem = xmalloc(sizeof(*elem))))
    return (NULL);
  elem->pid = pid;
  elem->next = list_pid;
  return (elem);
}

int		my_put_in_parser(t_parser *elem, char **tab, char *op)
{
  t_parser	*newelem;

  if (!(newelem = xmalloc(sizeof(*newelem))))
    return (-1);
  newelem->cmdtab = tab;
  newelem->operator = op;
  newelem->prev = elem->prev;
  newelem->next = elem;
  elem->prev->next = newelem;
  elem->prev = newelem;
  return (0);
}

void		my_delete_elem(t_parser *parser)
{
  parser->prev->next = parser->next;
  parser->next->prev = parser->prev;
  if (parser)
    free(parser);
}
