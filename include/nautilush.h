/*
** 42sh.h for  in /home/dong_n/rendu/42sheu
**
** Made by dong_n
** Login   <dong_n@epitech.net>
**
** Started on  Sun May  4 17:50:41 2014 dong_n
** Last update Tue Jun  3 13:39:32 2014 menigo_m
*/

#ifndef NAUTILUSH_H_
# define NAUTILUSH_H_

#include <glob.h>

typedef int		pid_t;

typedef struct		s_bin
{
  char			*name;
  struct s_bin		*next;
  struct s_bin		*prev;
}			t_bin;

typedef struct		s_hist
{
  char			*data;
  int			hist_elem;
  struct s_hist		*next;
  struct s_hist		*prev;
}			t_hist;

typedef struct		s_built_in
{
  char			*cmd;
  int			(*function)();
}			t_built_in;

typedef struct		s_key
{
  char			*cmp;
  char			*(*function)();
}			t_key;

typedef struct		s_env
{
  char			*key;
  char			*value;
  struct s_env		*next;
  struct s_env		*prev;
}			t_env;

typedef struct		s_alias
{
  char			*alias;
  char			**value;
  struct s_alias	*next;
  struct s_alias	*prev;
}			t_alias;

typedef struct		s_parser
{
  char			**cmdtab;
  char			*operator;
  struct s_parser	*prev;
  struct s_parser	*next;
}			t_parser;

typedef struct		s_pid
{
  pid_t			pid;
  struct s_pid		*next;
}			t_pid;

typedef struct		s_cmd
{
  int			fd[3];
  t_pid			*pid;
  t_env			*env;
  t_parser		*root;
  t_parser		*parser;
  char			**cmdtab;
  int			line;
  t_hist		*hist;
  t_alias		*alias;
}			t_cmd;

typedef struct		s_redir
{
  int			op;
  int			(*func)(t_cmd *cmd);
}			t_redir;

typedef struct		s_error
{
  int			status;
  char			*msg;
}			t_error;

# define IS_SEP(x)	((x > 0 && x < 33) || x > 126 ? 1 : 0)
# define EXIT_VALUE(x)	(((x + 256) % 256) + 256)
# define EXISTS(a, b)	(a ? a : b)

/*
** KEYCODE
*/
# define CTRL_A		"\001"
# define CTRL_B		"\002"
# define EOT		"\004"
# define CTRL_E		"\005"
# define CTRL_F		"\006"
# define CTRL_H		"\010"
# define TAB		"\011"
# define CTRL_L		"\014"
# define BACKSPACE	"\177"
# define ALT_BACKSPACE	"\033\177"
# define CTRL_RIGHT	"\033[1;5C"
# define CTRL_LEFT	"\033[1;5D"
# define ALT_RIGHT	"\033\133\061\073\063\103"
# define ALT_LEFT	"\033\133\061\073\063\104"
# define LEFT		"\033[D"
# define RIGHT		"\033[C"
# define DEL		"\033[3~"
# define UP		"\033[A"
# define DOWN		"\033[B"

/*
** BUILTINS
*/
char		*alias_file(t_env *env);
char		*get_alias_name(char *line);
char		*get_alias_value(char *line);
int		change_folder(t_cmd *cmd);
int		my_alias(t_cmd *cmd);
int		my_put_in_alias(t_alias *alias, char *alias_name, char *value);
t_alias		*get_alias(t_env *env);
int		my_echo(t_cmd *cmd);
int		my_env(t_cmd *cmd);
int		my_env_var(t_parser *parser, t_env *env);
int		my_exit(t_cmd *cmd);
int		my_setenv_key_value(t_env *env, char *key, char *value);
int		my_setenv(t_cmd *cmd);
int		my_unalias(t_cmd *cmd);
int		my_unsetenv(t_cmd *cmd);
char		**parse_alias(char *str);

/*
** src/parsing/assign_function.c
*/
int		assign_function(t_cmd *cmd);
int		exec_function(t_cmd *cmd);

/*
** src/parsing/char_to_list.c
*/
t_env		*char_to_list(char **envp);

/*
** src/parsing/check_eot.c
*/
int		check_eot(char *str);

/*
** src/parsing/cmdlen.c
*/
int		my_cmdlen(char *str);

/*
** src/parsing/epur_str.c
*/
char		*epur_str(char *str);

/*
** src/parsing/exec.c
*/
int		check_op(t_cmd *cmd);

/*
** src/parsing/exec_in_pipe.c
*/
int		gere_pipe(t_cmd *cmd);

/*
** src/parsing/gere_next_cmd.c
*/
int		gere_next_cmd(t_cmd *cmd, int status, int op);

/*
** src/parsing/gere_redirections.c
*/
int		double_left(t_cmd *cmd);
int		double_right(t_cmd *cmd);
int		gere_redirections(t_cmd *cmd, int op);
int		simple_left(t_cmd *cmd);
int		simple_right(t_cmd *cmd);

/*
** src/parsing/get_path.c
*/
char		*my_check_path(char **paths, char **cmdtab);
char		**my_get_paths(t_env *env);
int		cmd_not_found(char *path, char **paths, char **cmdtab);
int		my_find_cmd(char **paths, char **cmdtab);

/*
** src/parsing/init.c
*/
t_cmd		*init_cmd(int argc, char **argv, char **envp);
t_parser	*init_parser(void);

/*
** src/parsing/list_to_char.c
*/
char		**list_to_char(t_env *env);

/*
** src/parsing/my_builtins.c
*/
int		check_builtins(t_cmd *cmd);

/*
** src/parsing/my_errors.c
*/
int		my_child_error(int status);

/*
** src/parsing/my_getenv.c
*/
char		*my_getenv(char *str, t_env *env);

/*
** src/parsing/my_list.c
*/
int		my_put_in_parser(t_parser *elem, char **, char *op);
t_pid		*my_put_pid_in_list(t_pid *list_pid, pid_t pid);
void		my_delete_elem(t_parser *parser);

/*
** src/parsing/my_operators.c
*/
int		my_check_operator(char *str);
int		my_get_operator(char *str, char *newstr, int *i, int op);
void		my_operator_len(char *str, int *i, int *size, int op);

/*
** src/parsing/my_path_to_tab.c
*/
char		**my_path_to_tab(char *str);

/*
** src/parsing/my_tokenlen.c
*/
int		my_tokenlen(char *str);

/*
** src/parsing/parser.c
*/
t_parser	*my_get_parser(char *str);

/*
** src/parsing/replace_alias.c
*/
int		replace_by_alias(t_cmd *cmd);

/*
** src/parsing/reset_fd.c
*/
void		reset_fd(int *fd, int i);

/*
** src/parsing/reverse_syntax.c
*/
int		reverse_syntax(t_parser *parser);

/*
** src/prompt/autocomplete_binaries.c
*/
int		auto_binaries(t_cmd *cmd, char *line, t_bin *bin);
int		put_in_bin(t_bin *bin, char *name);

/*
** src/prompt/autocomplete.c
*/
char		*autocomplete(int *index, char *str, t_cmd *cmd);
char		*get_word(char *str, int *index, int star);
void		replace_index(char *str, t_cmd *cmd, t_bin *bin, int *index);

/*
** src/prompt/check_autocomplete.c
*/
int		auto_file(char *str, int *index, t_bin *bin, int star);
int		is_alpha(char c);
int		is_first_word(char *str, int index);
int		isnt_in_bin(char *str, t_bin *bin);

/*
** src/prompt/free_fcts.c
*/
void		free_bin(t_bin *bin);
void		free_cmd(t_cmd *cmd);
void		free_env(t_env *env);
void		free_final_bin(t_bin *bin);
void		free_hist(t_hist *hist);

/*
** src/prompt/gere_back_del.c
*/
char		*gere_alt_back(int *index, char *str, t_cmd *cmd);
char		*gere_back(int *index, char *str, t_cmd *cmd);
char		*gere_del(int *index, char *str, t_cmd *cmd);

/*
** src/prompt/gere_ctrl_directions.c
*/
char		*gere_ctrl_left(int *index, char *str, t_cmd *cmd);
char		*gere_ctrl_right(int *index, char *str, t_cmd *cmd);

/*
** src/prompt/gere_ctrl_letter.c
*/
char		*gere_ctrl_a(int *index, char *str, t_cmd *cmd);
char		*gere_ctrl_e(int *index, char *str, t_cmd *cmd);

/*
** src/prompt/gere_directions.c
*/
char		*gere_down(t_cmd *cmd, int *index, int *hist_elem, char *str);
char		*gere_left(int *index, char *str, t_cmd *cmd);
char		*gere_right(int *index, char *str, t_cmd *cmd);
char		*gere_up(t_cmd *cmd, int *index, int *hist_elem, char *str);

/*
** src/prompt/gere_history.c
*/
char		*get_elem(int hist_elem, t_hist *hist, int *flag);
int		epur_hist(t_hist *hist, char flag);
int		my_list_size(t_hist *hist);
void		delete_in_hist(t_hist *hist);

/*
** src/prompt/gere_key.c
*/
char		*clear_scr(int *index, char *str, t_cmd *cmd);
char		*gere_letter(int *index, char *c, char *str);

/*
** src/prompt/get_autocomplete_size.c
*/
int		get_little_size(t_bin *bin);
int		get_new_size(t_bin *bin);

/*
** src/prompt/globbing.c
*/
int		contain_star(char *str);
int		globing_in_cmd(t_parser *parser);
int		my_tab_size(char **);

/*
** src/prompt/history_built_in.c
*/
char		*check_last_hist(t_hist *hist, char *str);
int		gere_history(t_cmd *cmd);

/*
** src/prompt/history.c
*/
int		save_hist(t_hist *hist, t_env *env);
t_hist		*get_history(t_env *env);
t_hist		*init_history(void);

/*
** src/prompt/history_file.c
*/
char		*hist_file(t_env *env);

/*
** src/prompt/init_fcts.c
*/
char		*init_str(int *index);

/*
** src/prompt/is_empty.c
*/
int		is_empty(char *str);

/*
** src/prompt/my_histcpy.c
*/
char		*my_histcpy(char *dest, char *src);

/*
** src/prompt/print_binaries.c
*/
int		bin_size(t_bin *bin);
void		print_possibilities_or_not(t_bin *bin, int size);
void		print_possibilities(t_bin *bin);

/*
** src/prompt/prompt.c
*/
char		*gere_prompt(t_cmd *cmd);
int		prompt(t_cmd *cmd);

/*
** src/prompt/put_del_str.c
*/
char		*del_in_str(char *str, int index);
char		*put_in_str(char *str, int index, char *c);

/*
** src/prompt/put_in_hist.c
*/
int		my_put_in_list_rev(t_hist *hist, char *data);
int		my_put_in_list(t_hist *hist, char *data);

/*
** src/prompt/sort_bin.c
*/
int		sort_bin(t_bin *bin);

#endif /* !NAUTILUSH_H_ */
