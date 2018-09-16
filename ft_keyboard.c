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

int				quantity(t_arg *args)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = args;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			key_init(void)
{
	long key;

	while (1)
	{
		key = 0;
		read(0, &key, 8);
		korzinka()->i = row_init(korzinka()->arg);
		korzinka()->quant = quantity(korzinka()->arg);
		(key == 10) ? enter(&korzinka()->arg) : NULL;
		(key == DELETE || key == BACK) ? ft_del(&korzinka()->arg) : NULL;
		(key == SELECT) ? ft_select_item(&korzinka()->arg) : NULL;
		if (key == ESC)
		{
			reset_original();
			signal(SIGTSTP, SIG_DFL);
			exit(0);
		}
		(key == UP) ? ft_up(&korzinka()->arg) : NULL;
		(key == DOWN) ? ft_down(&korzinka()->arg) : NULL;
		(key == RIGHT) ? ft_right(&korzinka()->arg) : NULL;
		(key == LEFT) ? ft_left(&korzinka()->arg) : NULL;
		print_display(korzinka()->arg);
	}
}

void			print_list(t_arg *lst)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_putstr(tmp->name);
		ft_putstr(" ");
		tmp = tmp->next;
	}
}

int				get_col(struct winsize sz, int max_s)
{
	if (sz.ws_col % (max_s + 1) != 0)
		return (sz.ws_col / (max_s + 1));
	else
		return (sz.ws_col / (max_s + 1));
}

void			print_display(t_arg *args)
{
	struct winsize	sz;
	int				col_q;
	int				row_q;
	int				q;
	t_arg			*tmp;

	tmp = args;
	ioctl(0, TIOCGWINSZ, &sz);
	tputs(tgetstr("cl", NULL), 1, re_putchar);
	korzinka()->max_s = max_strlen(tmp);
	if (((korzinka()->max_s + 2) > (sz.ws_col - 4)) || (sz.ws_row < 1))
	{
		tputs(tgetstr("cl", NULL), 1, re_putchar);
		ft_error_display_size();
		return ;
	}
	q = struct_col(args);
	col_q = get_col(sz, korzinka()->max_s);
	row_q = get_row(col_q, q);
	if (row_q > sz.ws_row)
		print_more(args, col_q, sz);
	else
		print_norm(args, col_q);
}
