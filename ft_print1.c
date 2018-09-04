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

void			print_norm(t_arg *args, int row_q, int col_q)
{
	int		c;
	t_arg	*tmp;
	int		dif;

	c = col_q;
	tmp = args;
	while (tmp != NULL)
	{
		while (row_q--)
		{
			col_q = c;
			while (col_q--)
			{
				ft_putstr(tmp->name);
				if (max_strlen(args) > (int)ft_strlen(tmp->name))
					dif = max_strlen(args) - (int)ft_strlen(tmp->name);
				while (dif)
				{
					ft_putstr(" ");
					dif--;
				}
				tmp = tmp->next;
				ft_putstr("  ");
			}
			ft_putstr("\n");
		}
	}
}
