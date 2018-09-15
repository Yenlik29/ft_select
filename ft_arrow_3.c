/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:30:08 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/13 14:30:15 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg			*go_next(t_arg *tmp)
{
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void			tmp_on(t_arg *tmp, t_arg **args)
{
	tmp->on = 1;
	korzinka()->arg = *args;
}

t_arg			*f_i(t_arg *tmp, int *i)
{
	while (tmp)
	{
		if (tmp->on == 1)
			return (tmp);
		tmp = tmp->next;
		(*i)++;
	}
	return (tmp);
}

t_arg			*if_1(t_arg *tmp, t_arg **args, int i)
{
	int				count;
	t_arg			*lst;
	struct winsize	sz;
	int				col_q;
	int 			j;

	count = 0;
	lst = *args;
	tmp->on = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	col_q = get_col(sz, korzinka()->max_s);
	if ((K_MINUS * col_q) + i > korzinka()->quant)
		tmp = go_next(tmp);
	else
	{
		if (korzinka()->flag == 1)
		{
			while (tmp->next)
				tmp = tmp->next;
		}
		else
		{
			ft_putnbr(korzinka()->i);
			// j = korzinka()->quant - ((get_row(col_q, korzinka()->quant) - 1) * col_q);
			// ft_putnbr(korzinka()->quant - ((get_row(col_q, korzinka()->quant) - 1) * col_q));
			// while (j-- && lst)
			j = 0;
			exit(0);
		}
	}
	tmp_on(tmp, args);
	return (tmp);
}

t_arg			*f_else(t_arg *tmp, t_arg **args)
{
	int				count;
	struct winsize	sz;
	int				col_q;
	int				q;
	int 			col;

	count = 0;
	tmp->on = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	q = struct_col(tmp);
	col_q = get_col(sz, korzinka()->max_s);
	if (col_q != korzinka()->col)
	{
		col = w_col(tmp, korzinka()->col);
		while (col--)
			tmp = tmp->prev;
	}
	else
	{
		while (count++ != col_q)
			tmp = tmp->prev;
	}
	tmp_on(tmp, args);
	return (tmp);
}
