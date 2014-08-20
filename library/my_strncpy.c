/*
** my_strncpy.c for my_strncpy.c in /home/menigo_m/rendu/Piscine-C-Jour_06/ex_02
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Mon Oct  7 08:46:31 2013 a
** Last update Wed Oct  9 09:53:36 2013 a
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
