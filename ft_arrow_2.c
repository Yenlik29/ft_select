/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:50:34 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/11 19:50:42 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg			*d1(t_arg *tmp, t_arg **args, int i)
{
	int				col;
	struct winsize	sz;
	t_arg			*lst;
	int				col_q;

	lst = *args;
	ioctl(0, TIOCGWINSZ, &sz);
	col_q = get_col(sz, korzinka()->max_s);
	col = find(lst, col_q, i);
	tmp->on = 0;
	if ((i + col_q) > korzinka()->quant)
	{
		if (col_q == korzinka()->col)
		{
			while (col-- && lst)
				lst = lst->next;
			tmp = lst;
		}
		else
			tmp = lst;
	}
	else
	{
		while (i-- != 1)
			tmp = tmp->prev;
		while (i++ != col)
			tmp = tmp->next;
	}
	tmp_on(tmp, args);
	return (tmp);
}

t_arg			*d2(t_arg *tmp, t_arg **args, int i)
{
	struct winsize	sz;
	t_arg 			*lst;
	int				count;
	int				col_q;

	count = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	tmp->on = 0;
	col_q = get_col(sz, korzinka()->max_s);
	if (i == korzinka()->quant)
	{
		while (tmp->prev)
			tmp = tmp->prev;
	}
	else if ((i + korzinka()->col) > korzinka()->quant)
	{
		lst = *args;
		tmp = lst;
	}
	else
	{
		if (col_q != korzinka()->col)
		{
			while (korzinka()->col--)
				tmp = tmp->next;
		}
		else
		{
			while (count++ != col_q)
				tmp = tmp->next;	
		}
	}
	tmp_on(tmp, args);
	return (tmp);
}

void			work(t_arg *tmp, t_arg **args, int n)
{
	tmp->click = n;
	tmp->on = 0;
	if (!tmp->next)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->on = 1;
	}
	else
		tmp->next->on = 1;
	korzinka()->arg = *args;
}

int				find(t_arg *lst, int col_q, int i)
{
	int		begin;
	int		col;
	t_arg	*tmp;

	col = 0;
	begin = 0;
	tmp = lst;
	begin = (find_row(lst, i) - 1) * col_q;
	begin++;
	col = i - begin;
	return (col);
}

void			enter(t_arg **args)
{
	t_arg	*tmp;
	t_arg	*new;

	new = NULL;
	tmp = *args;
	while (tmp)
	{
		if (tmp->click == 1)
		{
			if (new == NULL)
				new = ft_create_arg(tmp->name);
			else
				new = ft_add_arg(new, tmp->name);
		}
		tmp = tmp->next;
	}
	reset_original();
	print_list(new);
	exit(0);
}
