/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:38:53 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/03 22:36:17 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int 			row_init(t_arg *args)
{
	struct winsize	sz;
	int 			max_s;
	int 			col_q;
	int				row_q;
	int 			q;

	ioctl(0, TIOCGWINSZ, &sz);
	max_s = max_strlen(args);
	q = struct_col(args);
	col_q = get_col(sz, max_s);
	row_q = get_row(col_q, q);
	return (row_q);
}

int 			reset_original()
{
	struct termios original;

	
	tcgetattr(0, &original);
	original.c_lflag |= ICANON;
	original.c_lflag |= ECHO;
	original.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &original);
	tputs(tgetstr("te", 0), 1, re_putchar);
	tputs(tgetstr("ve", 0), 1, re_putchar);
	if (tcsetattr(0, TCSANOW, &original)  != 0)
	{
		ft_error_tcsetattr();
		return (0);
	}
	return (1);
}

int 			terminal_define()
{
	struct termios	original;
	struct termios	copy;

	if (tcgetattr(0, &original) != 0)
	{
		ft_error_tcgetattr();
		return (0);
	}
	else
	{
		copy = original;
		copy.c_lflag &= ~ICANON;
		copy.c_lflag &= ~ECHO;
		copy.c_cc[VTIME] = 0;
		copy.c_cc[VMIN] = 1;
		if (tcsetattr(0, TCSANOW, &copy) != 0)
		{
			ft_error_tcsetattr();
			return (0);
		}
	}
	tputs(tgetstr("ti", NULL), 1, re_putchar);
	tputs(tgetstr("vi", NULL), 1, re_putchar);
	return (1);
}

int				terminal_init(void)
{
	char	*termtype;
	char	term_buf[2048];
	int 	success;

	if (!(isatty(0)))
	{
		ft_error_isatty();
		return (-1);
	}
	termtype = getenv("TERM");
	if (termtype == 0)
	{
		ft_error_noterm();
		exit(0);
	}
	success = tgetent(term_buf, termtype);
	(success < 0) ? ft_error_term_access() : NULL;
	(success == 0) ? ft_error_termdef(termtype) : NULL;
	return (success);
}

int				main(int argc, char **argv)
{
	t_arg *args;
	int ret;

	args = NULL;
	(argc < 2) ? ft_error_quantity() : NULL;
	if (argc > 1)
	{
		if ((ret = terminal_init()) <= 0)
			return (0);
		else
		{
			signal_s();
			args = argv_init(argv);
			korzinka()->arg = args;
			if (terminal_define() == 0)
				return (0);
			else
			{
				print_display(args);
				key_init();
				reset_original();
			}
		}
	}
	return (0);
}
