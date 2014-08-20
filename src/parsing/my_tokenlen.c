/*
** my_tokenlen.c for  in /home/dong_n/rendu/42sh/src/parsing
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Sat May 24 00:06:03 2014 dong_n
** Last update Sat May 24 11:43:10 2014 menigo_m
*/

#include "nautilush.h"

int		my_tokenlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] && !IS_SEP(str[i]))
    i++;
  return (i);
}
