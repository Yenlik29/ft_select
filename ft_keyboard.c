/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:26:48 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/30 19:26:57 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			key_init()
{
	int	nread;
	int	ch;

	ch = 0;
	while (1)
	{
		nread = read(0, &ch, 1);
		if (ch == ESC)
		{
			reset_original();
			exit(0);
		}
	}
}

int 			ft_count(char **argv)
{
	int	CP;
	int	QW;
	int	WML;
	int	length;
	int	N;

	QW = len(argv);
	CP = QW - 1;
	length = tgetnum("co");
	WML = max_l(argv);
	N = count_r_c(WML, CP);
	return (N);
}

void			print_norm(char **argv)
{
	int QW;
	int i;

	i = 1;
	QW = len(argv);
	while (argv[i] && i <= QW)
	{
		ft_putstr(argv[i]);
		ft_putstr("    ");
		i++;
	}
}

void			print_more(char **argv)
{
	int i;
	int L;
	int length;
	int WML;

	i = 2;
	L = tgetnum("co");
	WML = max_l(argv);
	length = count_r_c(WML, (len(argv) - 1));
	while ((L <= length) && (length < (L + L)))
	{
		printf("%d\n", (L * i));
		i++;
		L = L + L;
	}
	printf("len: %d\nL: %d\ni: %d\n", length, L, i);
}

void			print_argv(char **argv)
{
	int i;
	int n;
	int L;

	i = 1;
	n = ft_count(argv);
	L = tgetnum("co");
	if (n <= L)
		print_norm(argv);
	else
		print_more(argv);
	// Здесь должна быть формула для вывода
	// while (argv[i])
	// {
	// 	tputs(argv[i], 1, re_putchar);
	// 	ft_putstr("\n");
	// 	i++;
	// }
}
