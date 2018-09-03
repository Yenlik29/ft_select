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
	int		i;
	int		c;
	t_arg	*tmp;

	i = 0;
	c = col_q;
	tmp = args;
	while (tmp != NULL)
	{
		while (row_q)
		{
			col_q = c;
			while (col_q)
			{
				ft_putstr(tmp->name);
				tmp = tmp->next;
				ft_putstr("  ");
				col_q--;
			}
			ft_putstr("\n");
			row_q--;
		}
	}
}
