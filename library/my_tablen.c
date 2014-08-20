/*
** my_tablen.c for  in /home/dong_n/rendu/42sh/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Thu May  8 14:42:52 2014 dong_n
** Last update Thu May  8 15:12:04 2014 dong_n
*/

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
