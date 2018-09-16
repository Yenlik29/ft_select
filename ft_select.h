/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:39:57 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/25 11:40:35 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <termios.h>
# include <string.h>
# include <stdlib.h>
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft/libft.h"
# define ESC			27
# define SELECT			32
# define A				65
# define B				66
# define C				67
# define D				68
# define DELETE			127
# define UP				4283163
# define DOWN			4348699
# define RIGHT			4414235
# define LEFT			4479771
# define BACK			2117294875
# define C_NONE			"\033[0m"
# define C_RED			"\033[31m"
# define C_GREEN		"\033[32m"
# define C_BROWN		"\033[33m"
# define C_BLUE			"\033[34m"
# define C_WHITE		"\033[37m"
# define C_CYAN			"\033[36m"
# define C_MAGENTA		"\033[35"
# define C_PINK			"\e[38;5;175m"
# define C_PURPLE		"\033[01;38;05;55m"
# define C_NZN			"\e[38;5;82m"
# define K_MINUS		(korzinka()->i - 1)
# define SM				(i > nw.ws_row - 1)
# define MAX			(find_act(tmp, col) == 1)

typedef struct			s_arg
{
	char				*name;
	int					click;
	int					on;
	int					j;
	mode_t				st_mode;
	struct s_arg		*next;
	struct s_arg		*prev;
}						t_arg;

typedef struct			s_link
{
	int		i;
	int		j;
	int		quant;
	int		last;
	int		col;
	int		max_s;
	int		change;
	char	**av;
	int		flag;
	t_arg	*arg;
}						t_link;

int						terminal_init(void);
int						terminal_define(void);
int						reset_original(void);
int						row_init(t_arg *args);
int						w_col(t_arg *args, int col_q);

void					signal_s(void);
void					sighandler(int signum);

int						find_act(t_arg *args, int col_q);
int						max_row(t_arg *lst);
int						find_row(t_arg *args, int j);
int						column(t_arg *tmp);
void					output(t_arg *tmp, t_arg *args);

void					print_norm(t_arg *args, int col_q);
void					settings_off(t_arg *tmp);
void					settings_on(t_arg *tmp);
void					print_dif(int dif);
void					print_more(t_arg *args, int col_q, struct winsize sz);

t_arg					*argv_init(char **argv);
t_arg					*ft_add_arg(t_arg *lst, char *name);
t_arg					*ft_create_arg(char *name);
int						get_row(int col_q, int q);
int						struct_col(t_arg *args);

t_link					*korzinka(void);

void					ft_del(t_arg **args);
void					delete_node(t_arg **head, t_arg *del);
int						where(t_arg **args);

void					print_display(t_arg *args);
int						get_col(struct winsize sz, int max_s);
void					print_list(t_arg *lst);
void					key_init(void);
int						quantity(t_arg *args);

void					ft_error_tcsetattr(void);
void					ft_error_isatty(void);
void					ft_error_display_size(void);

void					ft_error_quantity(void);
void					ft_error_noterm(void);
void					ft_error_term_access(void);
void					ft_error_termdef(char *termtype);
void					ft_error_tcgetattr(void);

t_arg					*f_else(t_arg *tmp, t_arg **args);
t_arg					*if_1(t_arg *tmp, t_arg **args, int i);
t_arg					*f_i(t_arg *tmp, int *i);
void					tmp_on(t_arg *tmp, t_arg **args);
t_arg					*go_next(t_arg *tmp);

void					enter(t_arg **args);
int						find(t_arg *lst, int col_q, int i);
void					work(t_arg *tmp, t_arg **args, int n);
t_arg					*d2(t_arg *tmp, t_arg **args, int i);
t_arg					*d1(t_arg *tmp, t_arg **args, int i);

void					ft_right(t_arg **args);
void					ft_down(t_arg **args);
void					ft_left(t_arg **args);
void					ft_up(t_arg **args);
void					ft_select_item(t_arg **args);

int						re_putchar(int ch);
int						len(char **argv);
int						max_l(char **argv);
int						count_r_c(int wml, int space);
int						max_strlen(t_arg *args);

t_arg					*d2_1(int col_q, t_arg *tmp);
t_arg					*d1_1(int col_q, t_arg *tmp, t_arg *lst, int col);

#endif
