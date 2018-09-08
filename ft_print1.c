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

int				find_row(t_arg *args)
{
	int 	col;
	int		col_q;
	int 	row;
	t_arg	*tmp;

	row = 1;
	tmp = args;
	col_q = column(tmp);
	while (tmp)
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

void			print_new_line(t_arg *lst, int row, int col_q, struct winsize sz)
{
	int i;
	int c;
	int	j;
	int m_row;
	t_arg *tmp;

	i = 0;
	row++;
	c = col_q;
	j = korzinka()->j;
	tmp = lst;
	m_row = max_row(lst);
	while (i++ <= (sz.ws_row - 2) && tmp)
	{
		while (col_q--)
		{
			if (tmp)
			{
				if (row <= korzinka()->j)
				{
					tmp = tmp->next;
					row++;
					j++;
				}
				else
				{
					ft_putstr(tmp->name);
					ft_putstr(" ");
					ft_putnbr(row);
					ft_putstr("\n");
					row++;
					tmp = tmp->next;
				}
			}
		}
		col_q = c;
		ft_putstr("\n");
	}
	ft_putstr("...");
}

void			print_more(t_arg *args, int col_q, struct winsize sz)
{
	int		count;
	int		i;
	int		j;
	int		c;
	int		row;
	int		dif;
	t_arg	*tmp;
	t_arg	*lst;

	i = 0;
	c = col_q;
	tmp = args;
	lst = args;
	row = 1;
	j = 1;
	count = 0;
	while (i++ <= (sz.ws_row - 2) && tmp)
	{
		while (col_q--)
		{
			if (tmp)
			{
				row = find_row(lst);
				if (row <= sz.ws_row - 1)
				{
					if (tmp->click == 1)
						ft_putstr(C_RED);
					if (tmp->click == 0)
						ft_putstr(C_NONE);
					if (tmp->on == 1)
						tputs(tgetstr("us", 0), 1, re_putchar);
					ft_putstr(tmp->name);
					ft_putstr(" ");
					ft_putnbr(row);
					if (tmp->on == 1)
						tputs(tgetstr("me", 0), 1, re_putchar);
					if (tmp->click == 1)
						ft_putstr(C_NONE);
					if (max_strlen(args) >= (int)ft_strlen(tmp->name))
						dif = max_strlen(args) - (int)ft_strlen(tmp->name);
					print_dif(dif);
					tmp = tmp->next;
					ft_putstr("  ");
					korzinka()->j = j++;
				}
				else
				{
					while (count != korzinka()->j)
					{
						count++;
						tmp = tmp->next;
					}
					if (tmp->on == 1)
						tputs(tgetstr("us", 0), 1, re_putchar);
					ft_putstr(tmp->name);
					ft_putstr(" ");
					ft_putnbr(row);
					row = 1;
					if (tmp->on == 1)
						tputs(tgetstr("me", 0), 1, re_putchar);
					if (max_strlen(args) >= (int)ft_strlen(tmp->name))
						dif = max_strlen(args) - (int)ft_strlen(tmp->name);
					print_dif(dif);
					tmp = tmp->next;
					// tmp = tmp->next;
					// print_new_line(tmp, row, col_q, sz);
				}
			}
		}
		col_q = c;
		ft_putstr("\n");
	}
	ft_putstr("...");
}

void			print_dif(int dif)
{
	while (dif)
	{
		ft_putstr(" ");
		dif--;
	}
}

void			print_norm(t_arg *args, int row_q, int col_q)
{
	int		c;
	int		row;
	int		dif;
	t_arg	*tmp;

	row = 0;
	c = col_q;
	tmp = args;
	while (tmp)
	{
		while (row_q--)
		{
			while (col_q--)
			{
				if (tmp)
				{
					if (tmp->click == 1)
						ft_putstr(C_RED);
					if (tmp->click == 0)
						ft_putstr(C_NONE);
					if (tmp->on == 1)
						tputs(tgetstr("us", 0), 1, re_putchar);
					ft_putstr(tmp->name);
					if (tmp->on == 1)
						tputs(tgetstr("me", 0), 1, re_putchar);
					if (tmp->click == 1)
						ft_putstr(C_NONE);
					if (max_strlen(args) >= (int)ft_strlen(tmp->name))
						dif = max_strlen(args) - (int)ft_strlen(tmp->name);
					print_dif(dif);
					tmp = tmp->next;
					ft_putstr("  ");
				}
			}
			col_q = c;
			ft_putstr("\n");
		}
	}
}
