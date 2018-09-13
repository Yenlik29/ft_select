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

	count = 0;
	lst = *args;
	tmp->on = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	if (K_MINUS * COL + i > korzinka()->quant)
		tmp = go_next(tmp);
	else
	{
		while (count != (K_MINUS * COL))
		{
			tmp = tmp->next;
			count++;
		}
	}
	tmp_on(tmp, args);
	return (tmp);
}

t_arg			*f_else(t_arg *tmp, t_arg **args)
{
	int				count;
	struct winsize	sz;

	count = 0;
	tmp->on = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	while (count++ != COL)
		tmp = tmp->prev;
	tmp_on(tmp, args);
	return (tmp);
}
