##
## Makefile for  in /home/dong_n/rendu/42sh
## 
## Made by dong_n
## Login   <dong_n@epitech.net>
## 
## Started on  Thu May 15 16:20:50 2014 dong_n
## Last update Sun May 25 20:41:43 2014 menigo_m
##

CC	=	cc

NAME	=	nautiluSH

LIBSRC	=	library/my_putchar.c			\
		library/my_putstr.c			\
		library/my_strncpy.c			\
		library/my_strlen.c			\
		library/my_strcat.c			\
		library/my_put_nbr.c			\
		library/my_getnbr.c			\
		library/my_strcmp.c			\
		library/my_strcpy.c			\
		library/my_strdup.c			\
		library/xmalloc.c			\
		library/xfork.c				\
		library/get_next_line.c			\
		library/xcalloc.c			\
		library/my_tablen.c			\
		library/my_freetab.c

SRC	=	src/main.c				\
		src/prompt/prompt.c			\
		src/prompt/history.c			\
		src/prompt/gere_key.c			\
		src/prompt/is_empty.c			\
		src/prompt/put_in_hist.c		\
		src/prompt/put_in_bin.c			\
		src/prompt/free_fcts.c			\
		src/prompt/my_histcpy.c			\
		src/prompt/put_del_str.c		\
		src/prompt/init_fcts.c			\
		src/prompt/autocomplete.c		\
		src/prompt/print_binaries.c		\
		src/prompt/get_autocomplete_size.c	\
		src/prompt/autocomplete_binaries.c	\
		src/prompt/check_autocomplete.c		\
		src/prompt/gere_history.c		\
		src/prompt/history_file.c		\
		src/prompt/gere_ctrl_letter.c		\
		src/prompt/globbing.c			\
		src/prompt/gere_back_del.c		\
		src/prompt/history_built_in.c		\
		src/prompt/gere_directions.c		\
		src/prompt/gere_ctrl_directions.c	\
		src/prompt/sort_bin.c			\
		src/prompt/disp_prompt.c		\
		src/parsing/cmdlen.c			\
		src/parsing/parser.c			\
		src/parsing/my_list.c			\
		src/parsing/epur_str.c			\
		src/parsing/reset_fd.c			\
		src/parsing/my_getenv.c			\
		src/parsing/replace_alias.c		\
		src/parsing/char_to_list.c		\
		src/parsing/exec_in_pipe.c		\
		src/parsing/list_to_char.c		\
		src/parsing/my_operators.c		\
		src/parsing/reverse_syntax.c		\
		src/parsing/assign_function.c		\
		src/parsing/gere_redirections.c		\
		src/parsing/my_path_to_tab.c		\
		src/parsing/get_path.c			\
		src/parsing/my_errors.c			\
		src/parsing/init.c			\
		src/parsing/exec.c			\
		src/parsing/check_eot.c			\
		src/parsing/my_builtins.c		\
		src/parsing/gere_next_cmd.c		\
		src/parsing/my_tokenlen.c		\
		src/builtins/change_directory.c		\
		src/builtins/parse_alias.c		\
		src/builtins/my_echo.c			\
		src/builtins/my_exit.c			\
		src/builtins/my_setenv.c		\
		src/builtins/my_unsetenv.c		\
		src/builtins/my_env_var.c		\
		src/builtins/my_alias_built_in.c	\
		src/builtins/my_alias.c			\
		src/builtins/get_alias_elem.c		\
		src/builtins/my_unalias.c		\
		src/builtins/my_env.c

LIBOBJ	=	$(LIBSRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/
CFLAGS	+=	-W -Wall -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBOBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIBOBJ) -lncurses

clean	:
		$(RM) $(OBJ) $(LIBOBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
