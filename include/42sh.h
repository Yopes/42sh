/*
** 42sh.h for  in /home/dong_n/rendu/42sheu
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Sun May  4 17:50:41 2014 dong_n
** Last update Mon May  5 14:56:12 2014 dong_n
*/

#ifndef 42SH_H_
# define 42SH_H_

typedef struct		s_parser
{
  char			**cmdtab;
  char			*operande;
  struct s_parser	*prev;
  struct s_parser	*next;
}			t_parser;

int		my_cmdlen(char *str);
int		my_tokenlen(char *str);
int		my_check_operande(char *str);

#endif /* !42SH_H_ */
