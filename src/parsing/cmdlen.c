/*
** cmdlen.c for  in /home/dong_n/rendu/42sheu
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Mon May  5 14:18:29 2014 dong_n
** Last update Mon May 19 20:00:19 2014 dong_n
*/

#include "nautilush.h"
#include "my.h"

static void	my_quotelen(char *str, int *i, int *size)
{
  char		quote;

  quote = str[(*i)++];
  ++(*size);
  while (str[*i] && str[(*i)++] != quote)
    ++(*size);
  ++(*size);
  while (IS_SEP(str[*i]))
    ++(*i);
  if (IS_SEP(str[*i - 1]) && str[*i])
    ++(*size);
}

static void	my_operande_len(char *str, int *i, int *size)
{
  char		op;

  op = 0;
  while (str[*i] && !IS_SEP(str[*i]) && !op)
    {
      if (my_check_operator(&str[*i]) != -1)
	op = 1;
      else
	{
	  ++(*size);
	  ++(*i);
	}
    }
  while (IS_SEP(str[*i]))
    ++(*i);
  if (IS_SEP(str[*i - 1]) && str[*i])
    ++(*size);
}

int		my_cmdlen(char *str)
{
  int		i;
  char		op;
  int		size;

  i = 0;
  size = 0;
  while (IS_SEP(str[i]))
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '"' || str[i] == '\'')
	my_quotelen(str, &i, &size);
      else if ((op = my_check_operator(&str[i])) != -1)
	my_operator_len(str, &i, &size, op);
      else
	my_operande_len(str, &i, &size);
    }
  return (size);
}
