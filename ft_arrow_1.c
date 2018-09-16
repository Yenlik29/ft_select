/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:38:29 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/05 14:38:39 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_select_item(t_arg **args)
{
	int		count;
	t_arg	*tmp;

	count = 0;
	tmp = *args;
	while (tmp)
	{
		if (tmp->click == 1)
		{
			if (tmp->on == 1)
			{
				work(tmp, args, 0);
				return ;
			}
		}
		else if (tmp->click == 0)
		{
			if (tmp->on == 1)
			{
				work(tmp, args, 1);
				return ;
			}
		}
		tmp = tmp->next;
	}
}

void			ft_up(t_arg **args)
{
	t_arg			*tmp;
	int				i;
	t_arg			*lst;

	i = 1;
	lst = *args;
	tmp = *args;
	tmp = f_i(tmp, &i);
	while (tmp)
	{
		if (find_row(lst, i) == 1)
		{
			tmp = if_1(tmp, args, i);
			return ;
		}
		else
		{
			(tmp->on == 0) ? tmp = tmp->next : NULL;
			if (tmp->on == 1)
			{
				tmp = f_else(tmp, args);
				return ;
			}
		}
	}
}

void			ft_left(t_arg **args)
{
	t_arg *tmp;

	tmp = *args;
	while (tmp)
	{
		if (tmp->on == 1)
		{
			tmp->on = 0;
			if (!tmp->prev)
			{
				tmp = go_next(tmp);
				tmp->on = 1;
			}
			else
				tmp->prev->on = 1;
			korzinka()->arg = *args;
			return ;
		}
		tmp = tmp->next;
	}
}

void			ft_down(t_arg **args)
{
	int				i;
	t_arg			*tmp;
	t_arg			*lst;

	i = 1;
	tmp = *args;
	lst = *args;
	tmp = f_i(tmp, &i);
	while (tmp)
	{
		if (find_row(lst, i) == korzinka()->i)
		{
			// ft_putstr();
			tmp = d1(tmp, args, i);
			return ;
		}
		else
		{
			(tmp->on == 0) ? tmp = tmp->next : NULL;
			if (tmp->on == 1)
			{
				tmp = d2(tmp, args, i);
				return ;
			}
		}
	}
}

void			ft_right(t_arg **args)
{
	t_arg *tmp;

	tmp = *args;
	while (tmp)
	{
		if (tmp->on == 1)
		{
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
			return ;
		}
		tmp = tmp->next;
	}
}
