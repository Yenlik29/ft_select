/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_korz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:38:16 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/08 13:38:28 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_link			*korzinka(void)
{
	static t_link tmp;

	return (&tmp);
}

t_arg			*d2_1(int col_q, t_arg *tmp)
{
	int count;

	count = 0;
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
	return (tmp);
}

t_arg			*d1_1(int col_q, t_arg *tmp, t_arg *lst, int col)
{
	if (col_q == korzinka()->col)
	{
		while (col-- && lst)
			lst = lst->next;
		tmp = lst;
	}
	else
		tmp = lst;
	return (tmp);
}
