/*
** my_freetab.c for  in /home/dong_n/rendu/42sh
** 
** Made by dong_n
** Login   <dong_n@epitech.net>
** 
** Started on  Thu May 15 18:28:12 2014 dong_n
** Last update Tue May 20 11:28:48 2014 lopes_n
*/

#include <stdlib.h>

int	my_freetab(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (-1);
  while (tab[i])
    {
      free(tab[i]);
      i = i + 1;
    }
  return (0);
}
