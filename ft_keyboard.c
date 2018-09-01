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

void			print_list(t_arg *lst)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

t_glob *korzinka(void)
{
	static t_glob tmp;

	return (&tmp);
}
void			print_display(char **argv)
{
	struct winsize sz;
	t_arg *args;

	ioctl(0, TIOCGWINSZ, &sz);
	tputs(tgetstr("cl", NULL), 1, re_putchar);
	args = argv_init(argv);	
	print_list(args);
	//lst = NULL;
}
