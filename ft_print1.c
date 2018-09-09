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

int				column(t_arg *tmp)
{
	struct winsize	sz;
	int 			max_s;
	int 			col_q;

	ioctl(0, TIOCGWINSZ, &sz);
	max_s = max_strlen(tmp);
	col_q = get_col(sz, max_s);
	return (col_q);
}

int				find_row(t_arg *args, int j)
{
	int 	col;
	int 	count;
	int		col_q;
	int 	row;
	t_arg	*tmp;

	row = 1;
	count = 0;
	tmp = args;
	col_q = column(tmp);
	while (tmp)
	{
		while (count++ != j)
		{
			col = 1;
			while (col <= col_q)
			{
				if (tmp->on == 1)
					return (row);
				if (col == col_q)
					row++;
				col++;
				tmp = tmp->next;
			}
		}
	}
	return (row);
}

int				max_row(t_arg *lst)
{
	int 	col;
	int 	row;
	int		col_q;
	t_arg	*tmp;

	row = 1;
	tmp = lst;
	col_q = column(tmp);
	while (tmp)
	{
		col = 1;
		while (col <= col_q)
		{
			if (col == col_q)
				row++;
			col++;
			tmp = tmp->next;
		}
	}
	return (row);
}

int				find_act(t_arg *args)
{
	int		i;
	t_arg 	*tmp;

	i = 1;
	tmp = args;
	while (tmp)
	{
		if (tmp->on == 1)
			return (i);
		i++;
	}
	return (i);
}

void			print_more(t_arg *args, int col_q, struct winsize sz)
{
	int		i;
	int		j;
	int		c;
	int		dif;
	t_arg	*tmp;

	j = 1;
	i = find_act(args);
	c = col_q;
	tmp = args;
	while (i--)
		tmp = tmp->next;
	while (tmp && sz.ws_row--)
	{
		col_q = c;
		while (col_q--)
		{
			if (tmp)
			{
				settings_on(tmp);
				ft_putstr(tmp->name);
				settings_off(tmp);
				if (max_strlen(args) >= (int)ft_strlen(tmp->name))
					dif = max_strlen(args) - (int)ft_strlen(tmp->name);
				print_dif(dif);
				tmp = tmp->next;
				ft_putstr(" ");
			}
		}
		ft_putstr("\n");
	}
	ft_putstr("...");
}

void			print_dif(int dif)
{
	while (dif)
	{
		ft_putstr("*");
		dif--;
	}
}

void			settings_on(t_arg *tmp)
{
	if (tmp->click == 1)
		ft_putstr(C_RED);
	if (tmp->click == 0)
		ft_putstr(C_NONE);
	if (tmp->on == 1)
		tputs(tgetstr("us", 0), 1, re_putchar);
}

void			settings_off(t_arg *tmp)
{
	if (tmp->on == 1)
		tputs(tgetstr("me", 0), 1, re_putchar);
	if (tmp->click == 1)
		ft_putstr(C_NONE);
}

void			print_norm(t_arg *args, int col_q)
{
	int 	dif;
	int		col;
	t_arg 	*tmp;

	col = col_q;
	tmp = args;
	while (tmp)
	{
		col_q = col;
		while (col_q--)
		{
			if (tmp)
			{
				settings_on(tmp);
				ft_putstr(tmp->name);
				settings_off(tmp);
				if (max_strlen(args) >= (int)ft_strlen(tmp->name))
					dif = max_strlen(args) - (int)ft_strlen(tmp->name);
				print_dif(dif);
				tmp = tmp->next;
				ft_putstr(" ");
			}
		}
		ft_putstr("\n");
	}
}

