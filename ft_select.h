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
# define 	A 65
# define 	B 66
# define 	C 67
# define 	D 68

typedef struct 			s_arg
{
	char				*name;
	int					click;
	int					on;
	struct s_arg		*next;
}						t_arg;

typedef struct 			s_link
{
	char	**av;
	t_arg	*arg;
}						t_link;

int 			read_input();

t_link			*korzinka(void);
int				get_col(struct winsize sz, int max_s);
int 			get_row(int col_q, int q);
void			print_display(t_arg *args);

int				struct_col(t_arg *args);
t_arg			*ft_create_arg(char *name);
t_arg			*ft_add_arg(t_arg **lst, char *name);
void			print_list(t_arg *lst);
t_arg			*argv_init(char **argv);

void			print_dif(int dif);
void			print_more(t_arg *args, int col_q, struct winsize sz);
void			print_norm(t_arg *args, int row_q, int col_q);

void			print_argv(char **argv);
int 			ft_count(char **argv);
void			key_init();

int 			reset_original();
int 			terminal_define();
int				terminal_init(void);

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
