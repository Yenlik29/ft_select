/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:38:53 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/25 11:42:18 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int 			reset_original(struct termios original)
{
	if (tcsetattr(0, TCSANOW, &original)  != 0)
	{
		ft_error_tcsetattr();
		return (0);
	}
	return (1);
}

int 			terminal_define(char **argv)
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
		// copy.c_lflag &= ~ISIG;
		copy.c_cc[VTIME] = 0;
		copy.c_cc[VMIN] = 3;
		if (tcsetattr(0, TCSANOW, &copy) != 0)
		{
			ft_error_tcsetattr();
			return (0);
		}
	}
	tputs(tgetstr("ti", NULL), 1, re_putchar);
	tputs(tgetstr("vi", NULL), 1, re_putchar);
	tputs(tgetstr("cl", NULL), 1, re_putchar);
	int i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		// tputs(argv[i], 1, re_putchar);
		ft_putstr("\n");
		i++;
	}
	while (1)
	{
		
	}
	reset_original(original);
	argv = NULL;
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
	int ret;

	(argc < 2) ? ft_error_quantity() : NULL;
	if (argc > 1)
	{
		if ((ret = terminal_init()) <= 0)
			return (0);
		else
		{
			signal_s();
			if (terminal_define(argv) == 0)
				return (0);
		}
	}
	return (0);
}