/*
** get_next_line.h for 42sh in /home/menigo_m/rendu/42sh
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 11:29:17 2014 menigo_m
** Last update Fri May 23 11:29:17 2014 menigo_m
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define ABS(value) ((value < 0) ? -value : value)
# define BUFF_SIZE (1024)

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
