/*
** free_env.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src
**
** Made by menigo_m
** Login   <menigo_m@epitech.net>
**
** Started on  Wed May 14 10:39:14 2014 menigo_m
** Last update Tue May 20 11:27:33 2014 lopes_n
*/

#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

void		free_env(t_env *env)
{
  t_env		*tmp;

  tmp = env->next;
  while (tmp != env)
    {
      if (tmp->key != NULL)
	free(tmp->key);
      if (tmp->value != NULL)
	free(tmp->value);
      tmp = tmp->next;
      free(tmp->prev);
    }
  if (tmp->key != NULL)
    free(tmp->key);
  if (tmp->value != NULL)
    free(tmp->value);
  free(tmp);
}

void		free_hist(t_hist *hist)
{
  t_hist	*tmp;

  tmp = hist->next;
  while (tmp != hist)
    {
      if (tmp->data != NULL)
	free(tmp->data);
      tmp = tmp->next;
      free(tmp->prev);
    }
  if (tmp->data != NULL)
    free(tmp->data);
  free(tmp);
}

void		free_bin(t_bin *bin)
{
  t_bin		*tmp;
  t_bin		*to_delete;

  tmp = bin->next;
  while (tmp != NULL)
    {
      to_delete = tmp;
      tmp = tmp->next;
      free(to_delete);
    }
}

void		free_final_bin(t_bin *bin)
{
  t_bin		*tmp;
  t_bin		*to_delete;

  tmp = bin->next;
  while (tmp != NULL)
    {
      free(tmp->name);
      to_delete = tmp;
      tmp = tmp->next;
      free(to_delete);
    }
  free(bin);
}

void		free_cmd(t_cmd *cmd)
{
  t_parser	*parser;

  cmd->cmdtab = NULL;
  parser = cmd->root->next;
  while (parser != cmd->root)
    {
      my_freetab(parser->cmdtab);
      free(parser->cmdtab);
      free(parser->operator);
      parser = parser->next;
      free(parser->prev);
    }
  free(parser);
}
