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
	int		i;
	int		c;
	int		dif;
	t_arg	*tmp;

	i = 0;
	c = col_q;
	tmp = args;
	while (i++ <= (sz.ws_row - 2) && tmp)
	{
		while (col_q--)
		{
			if (tmp)
			{
				if (tmp->on == 1)
					tputs(tgetstr("us", 0), 1, re_putchar);
				ft_putstr(tmp->name);
				if (tmp->on == 1)
					tputs(tgetstr("me", 0), 1, re_putchar);
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
	int		dif;
	t_arg	*tmp;

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
					ft_putstr(tmp->name);
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
