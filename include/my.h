/*
** my.h for 42sh in /home/menigo_m/rendu/42sh
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 22:30:58 2014 menigo_m
** Last update Sat May 24 17:14:11 2014 menigo_m
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>

void		my_putchar(char c);
void		my_putchar_fd(char c, int fd);
void		my_putstr(char *str);
void		my_putstr_fd(char *str, int fd);
int		my_put_error(char *str);
int		my_strlen(const char *str);
int		my_getnbr(char *str);
int		my_strcmp(char *s1, char *s2);
void		my_put_nbr(int nbr);
void		my_put_nbr_fd(int nb, int fd);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strdup(char *src);
void		*xmalloc(size_t size);
void		*xcalloc(size_t nmemb, size_t size);
void		my_put_nbr(int nb);
int		my_tablen(char **ptr);
int		my_freetab(char **ptr);
char		*get_next_line(const int fd);
char		*my_strcat(char *dest, char *src);
pid_t		xfork(void);

#endif /* !MY_H_ */
