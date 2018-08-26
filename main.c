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

int				terminal_init(char **argv)
{
	char	*termtype;
	char	term_buf[2048];
	int 	success;

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
		if ((ret = terminal_init(argv)) <= 0)
			return (0);
	argv = NULL;
	return (0);
}
