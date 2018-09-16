/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:15:29 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/03 17:15:38 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			print_more(t_arg *args, int col_q, struct winsize sz)
{
	int				i;
	int				c;
	t_arg			*tmp;
	struct winsize	nw;

	c = col_q;
	tmp = args;
	i = find_act(tmp, col_q);
	korzinka()->max_s = max_strlen(tmp);
	korzinka()->last = korzinka()->max_s;
	korzinka()->col = col_q;
	korzinka()->flag = 1;
	ioctl(0, TIOCGWINSZ, &nw);
	while (tmp && --sz.ws_row)
	{
		col_q = c;
		while (col_q-- && tmp)
		{
			output(tmp, args);
			tmp = tmp->next;
		}
		ft_putstr_fd("\n", 2);
	}
	ft_putstr_fd("...", 2);
	(SM && (i <= korzinka()->i) && tmp) ? print_display(tmp) : NULL;
}

void			print_dif(int dif)
{
	while (dif)
	{
		ft_putstr_fd(" ", 2);
		dif--;
	}
}

void			settings_on(t_arg *tmp)
{
	if (tmp->click == 1)
		tputs(tgetstr("mr", NULL), 1, re_putchar);
	if (tmp->click == 0)
		ft_putstr_fd(C_NONE, 2);
	if (tmp->on == 1)
		tputs(tgetstr("us", 0), 1, re_putchar);
}

void			settings_off(t_arg *tmp)
{
	if (tmp->on == 1)
		tputs(tgetstr("me", 0), 1, re_putchar);
	if (tmp->click == 1)
		ft_putstr_fd(C_NONE, 2);
}

void			print_norm(t_arg *args, int col_q)
{
	int				i;
	int				col;
	t_arg			*tmp;
	struct winsize	sz;

	i = 0;
	col = col_q;
	tmp = args;
	korzinka()->max_s = MAX ? korzinka()->last : max_strlen(tmp);
	korzinka()->last = korzinka()->max_s;
	korzinka()->col = col_q;
	korzinka()->flag = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	while (tmp && i++ <= sz.ws_row)
	{
		col_q = col;
		while (col_q-- && tmp)
		{
			output(tmp, args);
			tmp = tmp->next;
		}
		(i != sz.ws_row) ? ft_putstr_fd("\n", 2) : NULL;
	}
}
