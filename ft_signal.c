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
	if (signum == 18)
	{
		printf(">suspended<\n");
		exit(0);
	}
	else if (signum == 28)
		printf("RESIZE\n");
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
