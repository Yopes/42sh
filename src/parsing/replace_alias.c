/*
** replace_alias.c for 42sh in /home/lopes_n/42sh/src/parsing
**
** Made by lopes_n
** Login   <lopes_n@epitech.net>
**
** Started on  Thu May 22 12:27:54 2014 lopes_n
** Last update Sat May 24 12:05:48 2014 menigo_m
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static int	replace_elem_alias(t_parser *tmp, char **alias)
{
  char		**new_tab;
  int		j;
  int		i;

  new_tab = xmalloc(sizeof(char *) * (my_tab_size(alias)
				      + my_tab_size(tmp->cmdtab)));
  if (!new_tab)
    return (-1);
  i = 0;
  j = 0;
  while (alias[j] != NULL)
    new_tab[i++] = my_strdup(alias[j++]);
  free(tmp->cmdtab[0]);
  j = 1;
  while (tmp->cmdtab && tmp->cmdtab[j])
    new_tab[i++] = tmp->cmdtab[j++];
  new_tab[i] = NULL;
  free(tmp->cmdtab);
  tmp->cmdtab = new_tab;
  return (0);
}

static void	find_alias(t_parser *pars, t_alias *alias)
{
  t_alias	*tmp;

  tmp = alias->next;
  while (tmp != alias)
    {
      if (my_strcmp(pars->cmdtab[0], tmp->alias) == 0)
	replace_elem_alias(pars, tmp->value);
      tmp = tmp->next;
    }
}

int		replace_by_alias(t_cmd *cmd)
{
  t_parser	*tmp;

  tmp = cmd->parser->next;
  while (tmp != cmd->parser)
    {
      find_alias(tmp, cmd->alias);
      tmp = tmp->next;
    }
  return (0);
}
