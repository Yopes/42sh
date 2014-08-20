/*
** prompt.h for 42sh in /home/menigo_m/rendu/42sh
** 
** Made by menigo_m
** Login   <menigo_m@epitech.net>
** 
** Started on  Fri May 23 11:29:13 2014 menigo_m
** Last update Fri May 23 11:29:13 2014 menigo_m
*/

#ifndef PROMPT_H_
# define PROMPT_H_

t_env	*char_to_list(char **env);
char	**list_to_char(t_env *env);
int	my_setenv(t_env *env, char **cmd);
char	*my_getenv(char *str, t_env *env);
void	my_unsetenv(t_env *env, char *str);
int	my_setenv_key_value(t_env *env, char *key, char *value);
int	change_folder(char **cmd, t_env *env);
void	my_env(t_env *env);
void	my_putstr(char *str);
void	my_putchar(char c);
void	my_show_list(t_hist *hist);
int	my_put_in_list(t_hist *hist, char *data);
t_hist	*get_history(t_env *env);
int	save_hist(t_hist *hist, t_env *env);
char	*gere_back(int *index, char *str);
char	*gere_del(int *index, char *str);
char	*gere_letter(int *index, char *c, char *str);
char	*gere_right(int *index, char *str);
char	*gere_left(int *index, char *str);
char	*del_in_str(char *str, int index);
char	*put_in_str(char *str, int index, char *c);
int	my_put_in_list_rev(t_hist *hist, char *data);
char	*get_elem(int hist_elem, t_hist *hist, int *flag);
char	*gere_up(t_hist *hist, int *index, int *hist_elem, char *str);
char	*gere_down(t_hist *hist, int *index, int *hist_elem, char *str);
char	*gere_ctrl_left(int *index, char *str);
char	*gere_ctrl_right(int *index, char *str);
char	*gere_ctrl_up(t_hist *hist, int *index, int *hist_elem, char *str);
char	*gere_ctrl_down(t_hist *hist, int *index, int *hist_elem, char *str);
int	my_list_size(t_hist *hist);
char	*gere_ctrl_e(int *index, char *str);
char	*gere_ctrl_a(int *index, char *str);
char	*autocomplete(int *index, char *str);
char	*clear_scr(int *index, char *str);
char	*my_histcpy(char *dest, char *src);
int	is_empty(char *str);
int	epur_hist(t_hist *hist, char flag);
int	del_history(t_hist *hist, t_env *env);
void	delete_in_hist(t_hist *hist);
char	*check_last_hist(t_hist *hist, char *str);
int	show_history(t_hist *hist);
char	*hist_file(t_env *env);
void	free_env(t_env *env);
void	free_hist(t_hist *hist);
char	*gere_alt_back(int *index, char *str);
int	prompt(t_env *env);
t_hist	*gere_prompt(t_hist *hist, char **str);

/*
** KEYCODE
*/
# define	CTRL_A	        "\001"
# define	CTRL_B	        "\002"
# define	EOT		"\004"
# define	CTRL_E	        "\005"
# define	CTRL_F	        "\006"
# define	TAB	        "\011"
# define	CTRL_L	        "\014"
# define	BACKSPACE	"\177"
# define	ALT_BACKSPACE	"\033\177"
# define	CTRL_RIGHT	"\033[1;5C"
# define	CTRL_LEFT	"\033[1;5D"
# define	LEFT		"\033[D"
# define	RIGHT		"\033[C"
# define	DEL		"\033[3~"
# define	UP		"\033[A"
# define	DOWN		"\033[B"

#endif /* !PROMPT_H_ */
