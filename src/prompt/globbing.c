/*
** globing.c for 42sh in /home/lopes_n/rendu/42sh/src/parsing
**
** Made by lopes_n
** Login   <lopes_n@epitech.net>
**
** Started on  Thu May 15 20:21:53 2014 lopes_n
** Last update Sun May 25 20:15:03 2014 menigo_m
*/

#include <stdlib.h>
#include <glob.h>
#include "nautilush.h"
#include "my.h"

int	my_tab_size(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}

int		contain_star(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
      if (str[i] == '*')
	return (1);
      i = i + 1;
    }
  return (0);
}

static int	place_result_in_tab(t_parser *tmp, int i, glob_t pglob)
{
  char		**new_tab;
  int		j;
  int		k;

  new_tab = xmalloc(sizeof(char *) * ((int)pglob.gl_pathc
				      + my_tab_size(tmp->cmdtab)));
  if (!new_tab)
    return (-1);
  j = -1;
  while (++j < i)
    new_tab[j] = tmp->cmdtab[j];
  k = 0;
  while (k < (int)pglob.gl_pathc)
    new_tab[j++] = pglob.gl_pathv[k++];
  free(tmp->cmdtab[i++]);
  while (tmp->cmdtab[i])
    new_tab[j++] = tmp->cmdtab[i];
  new_tab[j] = NULL;
  free(tmp->cmdtab);
  tmp->cmdtab = new_tab;
  return (0);
}

static int	find_match(t_parser *tmp, int i)
{
  glob_t	pglob;
  int		ret;

  if (contain_star(tmp->cmdtab[i]) == 0)
    return (0);
  ret = glob(tmp->cmdtab[i], GLOB_ERR | GLOB_TILDE | GLOB_MARK, NULL, &pglob);
  if (ret == GLOB_NOSPACE)
    return (my_put_error("Glob failed\n"));
  if (ret == GLOB_NOMATCH || ret == GLOB_ABORTED)
    return (0);
  if ((int)pglob.gl_pathc <= 0)
    return (-1);
  if (place_result_in_tab(tmp, i, pglob) == -1)
    return (-1);
  return (0);
}

int		globing_in_cmd(t_parser *parser)
{
  t_parser	*tmp;
  int		i;

  if (isatty(0) == 0)
    return (0);
  tmp = parser->next;
  while (tmp != parser)
    {
      i = 0;
      while (tmp->cmdtab[i] != NULL)
	{
	  if (find_match(tmp, i) == -1)
	    return (-1);
	  i = i + 1;
	}
      tmp = tmp->next;
    }
  return (0);
}
