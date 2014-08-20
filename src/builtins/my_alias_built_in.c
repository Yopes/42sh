/*
** my_alias_built_in.c for 42sh in /home/menigo_m/rendu/42sh
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Thu May 22 10:08:15 2014 menigo_m
** Last update Sat May 24 12:07:29 2014 menigo_m
*/

#include <fcntl.h>
#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static void	print_alias(t_alias *alias)
{
  t_alias	*tmp;
  int		i;

  tmp = alias->prev;
  while (tmp != alias)
    {
      i = 0;
      my_putstr(tmp->alias);
      my_putchar('=');
      while (tmp->value && tmp->value[i])
	{
	  my_putstr(tmp->value[i]);
	  i = i + 1;
	  if (tmp->value[i])
	    my_putchar(' ');
	}
      tmp = tmp->prev;
      my_putchar('\n');
    }
}

static int	replace_alias(t_alias *tmp, char *value)
{
  char		**tab;

  if (!(tab = parse_alias(value)))
    return (-1);
  my_freetab(tmp->value);
  free(tmp->value);
  tmp->value = tab;
  return (0);
}

static void	write_alias_file(t_alias *tmp, int fd)
{
  int		i;

  i = 0;
  write(fd, tmp->alias, my_strlen(tmp->alias));
  write(fd, "=", 1);
  while (tmp->value && tmp->value[i])
    {
      write(fd, tmp->value[i], my_strlen(tmp->value[i]));
      i = i + 1;
      if (tmp->value[i])
	write(fd, " ", 1);
    }
  write(fd, "\n", 1);
}

static int	save_alias(t_alias *alias, t_env *env)
{
  t_alias	*tmp;
  int		fd;
  char		*file;

  tmp = alias->prev;
  if ((file = alias_file(env)) == NULL)
    return (-1);
  if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (my_put_error("Open of .nautilurc failed\n"));
  free(file);
  while (tmp != alias)
    {
      write_alias_file(tmp, fd);
      tmp = tmp->prev;
    }
  close (fd);
  return (0);
}

int		my_alias(t_cmd *cmd)
{
  t_alias	*tmp;
  char		*name;

  if (cmd->cmdtab[1] == NULL)
    print_alias(cmd->alias);
  else if (cmd->cmdtab[1] && cmd->cmdtab[2])
    {
      tmp = cmd->alias->next;
      while (tmp != cmd->alias)
	{
	  if (my_strcmp(tmp->alias, cmd->cmdtab[1]) == 0)
	    return (replace_alias(tmp, cmd->cmdtab[2]));
	  tmp = tmp->next;
	}
      if (!(name = my_strdup(cmd->cmdtab[1])))
	return (-1);
      my_put_in_alias(cmd->alias, name, cmd->cmdtab[2]);
    }
  else
    return (my_put_error("Usage : alias [name] [value]\n"));
  if (save_alias(cmd->alias, cmd->env) == -1)
    return (-1);
  return (0);
}
