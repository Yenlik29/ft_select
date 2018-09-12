/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 22:17:59 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/12 22:18:07 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			output(t_arg *tmp, t_arg *args)
{
	int dif;

	dif = 0;
	settings_on(tmp);
	ft_putstr_fd(tmp->name, 2);
	ft_putstr_fd(C_NONE, 2);
	settings_off(tmp);
	if (max_strlen(args) >= (int)ft_strlen(tmp->name))
		dif = max_strlen(args) - (int)ft_strlen(tmp->name);
	print_dif(dif);
	ft_putstr_fd(" ", 2);
}

int				column(t_arg *tmp)
{
	struct winsize	sz;
	int				max_s;
	int				col_q;

	ioctl(0, TIOCGWINSZ, &sz);
	max_s = max_strlen(tmp);
	col_q = get_col(sz, max_s);
	return (col_q);
}

int				find_row(t_arg *args, int j)
{
	int		col;
	int		count;
	int		col_q;
	int		row;
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
	int		col;
	int		row;
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

int				find_act(t_arg *args, int col_q)
{
	int		row;
	int		j;
	int		col;
	t_arg	*tmp;

	row = 1;
	tmp = args;
	while (tmp)
	{
		col = 0;
		while (col <= col_q)
		{
			if (tmp->on == 1)
				j = row;
			if (col == col_q)
				row++;
			col++;
		}
		tmp = tmp->next;
	}
	if (j % col_q != 0)
		row = (j / col_q) + 1;
	else
		row = j / col_q;
	return (row);
}
