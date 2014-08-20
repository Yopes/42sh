/*
** my_strcmp.c for 42sh in /home/menigo_m/rendu/42sh
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 11:29:23 2014 menigo_m
** Last update Fri May 23 11:29:23 2014 menigo_m
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  if (s1 == NULL)
    return (-(*s2));
  if (s2 == NULL)
    return (*s1);
  while (*s1 != '\0' && *s2 != '\0')
    {
      if (*s1 == *s2)
	{
	  s1 = s1 + 1;
	  s2 = s2 + 1;
	}
      else
	return (*s1 - *s2);
    }
  if (*s1 != '\0' && *s2 == '\0')
    return (1);
  else if (*s1 == '\0' && *s2 != '\0')
    return (-1);
  return (0);
}
