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
# define 	UP 72
# define 	DOWN 80
# define 	RIGHT 77
# define 	LEFT 75

typedef struct 			s_arg
{
	char				*name;
	int					click;
	int					on;
}						t_arg;

void 			print_more(char **argv);
void			print_argv(char **argv);
int 			ft_count(char **argv);
void			key_init();

int 			reset_original();
int 			terminal_define();
int				terminal_init(void);

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

void			ft_error_tcsetattr(void);
void			ft_error_isatty(void);

#endif
