/*
** is_empty.c for 42sh in /home/menigo_m/rendu/PSU_2013_42sh/src
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May  9 13:39:25 2014 menigo_m
** Last update Fri May  9 13:39:28 2014 menigo_m
*/

int	is_empty(char *str)
{
  int	i;

  if (!str)
    return (1);
  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (0);
      i = i + 1;
    }
  return (1);
}
