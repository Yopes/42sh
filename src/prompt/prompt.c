/*
** prompt.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 13:37:39 2014 menigo_m
** Last update Sun May 25 19:19:48 2014 menigo_m
*/

#include <string.h>
#include "my.h"
#include "nautilush.h"

static const t_key	g_key[] = {
  {LEFT, &gere_left},
  {RIGHT, &gere_right},
  {CTRL_A, &gere_ctrl_a},
  {CTRL_B, &gere_left},
  {CTRL_E, &gere_ctrl_e},
  {CTRL_LEFT, &gere_ctrl_left},
  {CTRL_RIGHT, &gere_ctrl_right},
  {ALT_BACKSPACE, &gere_alt_back},
  {BACKSPACE, &gere_back},
  {DEL, &gere_del},
  {TAB, &autocomplete},
  {CTRL_L, &clear_scr},
  {CTRL_F, &gere_right},
  {ALT_LEFT, &gere_ctrl_left},
  {ALT_RIGHT, &gere_ctrl_right},
  {CTRL_H, &gere_back}
};

static const t_key	g_history[] = {
  {UP, &gere_up},
  {DOWN, &gere_down}
};

static int	gere_key(char *buf)
{
  int		i;

  i = 0;
  while (i < 16)
    {
      if (g_key[i].cmp && buf)
	if (strncmp(g_key[i].cmp, buf, my_strlen(g_key[i].cmp)) == 0)
	  return (i);
      ++i;
    }
  return (-1);

}

static int	check_history(char *buf)
{
  int		i;

  i = 0;
  while (i < 2)
    {
      if (g_history[i].cmp && buf)
	if (strncmp(g_history[i].cmp, buf, my_strlen(g_history[i].cmp)) == 0)
	  return (i);
      ++i;
    }
  return (-1);
}

static char	*check_fct(char *buf, char *str, int *index, t_cmd *cmd)
{
  int		i;

  if ((i = gere_key(buf)) != -1)
    str = g_key[i].function(index, str, cmd);
  else
    {
      if ((i = check_history(buf)) != -1)
	str = g_history[i].function(cmd, index, &(cmd->hist->hist_elem), str);
      else if (strncmp(buf, EOT, my_strlen(EOT)) == 0)
	{
	  free_hist(cmd->hist);
	  return (NULL);
	}
      else if (buf[0] >= 32 && buf[0] <= 126)
	str = gere_letter(index, buf, str);
    }
  memset(buf, 0, 8);
  return (str);
}

static char	*hist_or_not(t_cmd *cmd, char *str)
{
  char		*tmp;

  if (!(tmp = check_last_hist(cmd->hist, str)))
    return (str);
  str = tmp;
  my_putstr("\n");
  epur_hist(cmd->hist, 0);
  return (str);
}

char		*gere_prompt(t_cmd *cmd)
{
  char		buf[8];
  int		rd;
  int		index;
  char		*str;

  cmd->hist->hist_elem = 0;
  if (!(str = init_str(&index)))
    return (NULL);
  memset(buf, 0, 8);
  while ((rd = read(0, buf, 7)) > 0 && buf[0] != '\n')
    if ((str = check_fct(buf, str, &index, cmd)) == NULL)
      return (NULL);
  if (rd <= 0)
    return (NULL);
  str = hist_or_not(cmd, str);
  if (str != NULL)
    if (is_empty(str) == 0 && my_put_in_list_rev(cmd->hist, str) == -1)
      {
	free_hist(cmd->hist);
	return (NULL);
      }
  return (str);
}
