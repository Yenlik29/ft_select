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
	if (signum == SIGTSTP)
	{
		reset_original();
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	else if (signum == 19)
	{
		terminal_init();
		terminal_define();
		print_display(korzinka()->arg);
		signal_s();
	}
	else if (signum == 28)
		print_display(korzinka()->arg);
	else
	{
		reset_original();
		exit(0);
	}
}

void			signal_s(void)
{
	signal(SIGINT, sighandler);
	signal(SIGABRT, sighandler);
	signal(SIGTSTP, sighandler);
	signal(SIGWINCH, sighandler);
	signal(SIGCONT, sighandler);
	signal(SIGTERM, sighandler);
	signal(SIGKILL, sighandler);
	signal(SIGSTOP, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGHUP, sighandler);
	signal(SIGSEGV, sighandler);
	signal(SIGFPE, sighandler);
	signal(SIGALRM, sighandler);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
}
