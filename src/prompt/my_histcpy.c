/*
** my_histcpy.c for 42sh in /home/menigo_m/rendu/42sh/prompt_history
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Tue May  6 13:38:52 2014 menigo_m
** Last update Tue May  6 13:38:54 2014 menigo_m
*/

char	*my_histcpy(char *dest, char *src)
{
  int	i;
  int	y;

  y = 0;
  i = 0;
  while (src[i] != '\0')
    {
      if (src[i] >= 32 && src[i] <= 126)
	{
	  dest[y] = src[i];
	  y = y + 1;
	}
      i = i + 1;
    }
  dest[y] = '\0';
  return (dest);
}
