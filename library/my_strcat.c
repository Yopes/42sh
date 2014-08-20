/*
** my_strcat.c for my_strcat.c in /home/menigo_m/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue Oct  8 09:23:25 2013 a
** Last update Thu Dec 19 09:25:49 2013 a
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
