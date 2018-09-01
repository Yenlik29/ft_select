/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:27:42 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/28 16:27:55 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			sighandler(int signum)
{
	struct termios original;

	if (signum == 18)
	{
		tcgetattr(0, &original);
		original.c_lflag |= ICANON;
		original.c_lflag |= ECHO;
		original.c_cc[VMIN] = 1;
		tcsetattr(0, TCSANOW, &original);
		tputs(tgetstr("te", 0), 1, re_putchar);
		tputs(tgetstr("ve", 0), 1, re_putchar);
		printf(">suspended - need to work on it (fg)\n");
		signal(SIGTSTP, SIG_DFL);
		exit(0);
	}
	else if (signum == 19)
	{
		terminal_init();
		terminal_define();
		signal_s();
		// print_list();
	}
	else if (signum == 28)
		print_display(korzinka()->av);
	else
		signal(signum, SIG_IGN);
}

void			signal_s()
{
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGABRT, sighandler);
	signal(SIGTSTP, sighandler);
	signal(SIGWINCH, sighandler);
}
