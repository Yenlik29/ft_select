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

#ifndef FT_SELECT
# define FT_SELECT
# include	<unistd.h>
# include	<stdio.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<termios.h>
# include	<string.h>
# include	<stdlib.h>
# include	<termcap.h>
# include	<term.h>
# include	<curses.h>
# include	<signal.h>
# include	<sys/ioctl.h>
# include	"libft/libft.h"
# define 	ESC 27
# define 	SELECT 32
# define 	A 65
# define 	B 66
# define 	C 67
# define 	D 68
# define 	DELETE 127
# define    UP 4283163
# define    DOWN 4348699
# define    RIGHT 4414235
# define    LEFT 4479771
# define 	BACK 2117294875
# define 	C_NONE		"\033[0m"
# define 	C_RED		"\033[31m"
# define 	C_GREEN	"\033[32m"
# define 	C_BROWN	"\033[33m"
# define 	C_BLUE		"\033[34m"
# define 	C_WHITE	"\033[37m"
# define 	C_CYAN		"\033[36m"
# define 	C_MAGENTA	"\033[35"

typedef struct 			s_arg
{
	char				*name;
	int					click;
	int					on;
	int					j;
	struct s_arg		*next;
	struct s_arg		*prev;
}						t_arg;

typedef struct 			s_link
{
	int 	i;
	int		quant;
	char	**av;
	t_arg	*arg;
}						t_link;

t_link			*korzinka(void);
int				st_int();

void			settings_on(t_arg *tmp);
void			settings_off(t_arg *tmp);
int 			row_init(t_arg *args);
int 			quantity(t_arg *args);

int				find_act(t_arg *args, int col_q);
int				get_col(struct winsize sz, int max_s);
int 			get_row(int col_q, int q);
void			print_display(t_arg *args);

int				struct_col(t_arg *args);
t_arg			*ft_create_arg(char *name);
t_arg			*ft_add_arg(t_arg *lst, char *name);
void			print_list(t_arg *lst);
t_arg			*argv_init(char **argv);

int				column(t_arg *tmp);
int				find_row(t_arg *args, int j);
void			print_dif(int dif);
void			print_more(t_arg *args, int col_q, struct winsize sz);
void			print_norm(t_arg *args, int col_q);

void			print_argv(char **argv);
int 			ft_count(char **argv);
void			key_init();

int 			reset_original();
int 			terminal_define();
int				terminal_init(void);

void			ft_up(t_arg **args);
void			ft_right(t_arg **args);
void			ft_down(t_arg **args);
void			ft_left(t_arg **args);
void			ft_del(t_arg **args);
t_arg			*make_cycle(t_arg *lst, int i);
void			ft_select_item(t_arg **args);

int				max_strlen(t_arg *args);
int				count_r_c(int WML, int CP);
int				max_l(char	**argv);
int				len(char **argv);
int				re_putchar(int ch);

void			sighandler(int signum);
void			signal_s();

void			ft_error_tcgetattr(void);
void			ft_error_quantity();
void			ft_error_noterm();
void			ft_error_term_access();
void			ft_error_termdef(char *termtype);

void			ft_error_display_size(void);
void			ft_error_tcsetattr(void);
void			ft_error_isatty(void);

#endif
