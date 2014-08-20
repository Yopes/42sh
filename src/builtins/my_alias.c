/*
** my_alias.c for 42sh in /home/menigo_m/rendu/42sh/src
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Thu May 22 09:21:52 2014 menigo_m
** Last update Sat May 24 12:08:11 2014 menigo_m
*/

#include <fcntl.h>
#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static t_alias	*init_alias(void)
{
  t_alias	*alias;

  alias = xcalloc(1, sizeof(*alias));
  if (alias == NULL)
    return (NULL);
  alias->prev = alias;
  alias->alias = NULL;
  alias->value = NULL;
  alias->next = alias;
  return (alias);
}

int		my_put_in_alias(t_alias *alias, char *alias_name, char *value)
{
  t_alias	*element;
  char		**tab;

  if (!(tab = parse_alias(value)))
    return (-1);
  element = xmalloc(sizeof(*element));
  if (element == NULL)
    return (-1);
  element->alias = alias_name;
  element->value = tab;
  element->prev = alias;
  element->next = alias->next;
  alias->next->prev = element;
  alias->next = element;
  return (0);
}

static int	get_alias_line(int fd, t_alias *alias)
{
  char		*line;
  char		*alias_name;
  char		*value;

  while ((line = get_next_line(fd)) != NULL)
    {
      if (is_empty(line) == 0)
	{
	  if (!(alias_name = get_alias_name(line)))
	    return (-1);
	  if (!(value = get_alias_value(line)))
	    return (-1);
	  if (my_put_in_alias(alias, alias_name, value) == -1)
	    return (-1);
	}
      else
      	free(line);
    }
  return (0);
}

t_alias		*get_alias(t_env *env)
{
  t_alias	*alias;
  int		fd;
  char		*file;

  if ((alias = init_alias()) == NULL)
    return (NULL);
  file = alias_file(env);
  if (file == NULL)
    return (alias);
  fd = open(file, O_RDONLY);
  free(file);
  if (fd <= 0)
    return (alias);
  if (get_alias_line(fd, alias) == -1)
    return (alias);
  close (fd);
  return (alias);
}
