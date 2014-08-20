/*
** my_strlen.c for library in /home/dong_n/Documents
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Wed Apr 23 13:06:33 2014 dong_n
** Last update Tue May  6 14:29:56 2014 menigo_m
*/

int	my_strlen(const char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
