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
	t_arg *tmp;

	tmp = *args;
	while (tmp)
	{
		if (tmp->click == 1)
		{
			if (tmp->on == 1)
			{
				tmp->click = 0;
				tmp->on = 0;
				tmp->next->on = 1;
				korzinka()->arg = *args;
				return ;
			}
		}
		else if (tmp->click == 0)
		{
			if (tmp->on == 1)
			{
				tmp->click = 1;
				tmp->on = 0;
				tmp->next->on = 1;
				korzinka()->arg = *args;
				return ;
			}
		}
		tmp = tmp->next;
	}
}

void			ft_up(t_arg **args)
{
	int				count;
	t_arg			*tmp;
	struct winsize	sz;
	int				max_s;
	int				col_q;

	count = 0;
	tmp = *args;
	max_s = max_strlen(*args);
	ioctl(0, TIOCGWINSZ, &sz);
	col_q = get_col(sz, max_s);
	while (tmp)
	{
		if (tmp->on == 0)
			tmp = tmp->next;
		if (tmp->on == 1)
		{
			tmp->on = 0;
			while (count++ != col_q)
				tmp = tmp->prev;
			tmp->on = 1;
			korzinka()->arg = *args;
			return ;
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
				while (tmp->next)
					tmp = tmp->next;
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
	t_arg			*tmp;
	int				count;
	struct winsize	sz;
	int				max_s;
	int				col_q;

	count = 0;
	tmp = *args;
	max_s = max_strlen(*args);
	ioctl(0, TIOCGWINSZ, &sz);
	col_q = get_col(sz, max_s);
	while (tmp)
	{
		if (tmp->on == 0)
			tmp = tmp->next;
		if (tmp->on == 1)
		{
			tmp->on = 0;
			while (count++ != col_q)
				tmp = tmp->next;
			tmp->on = 1;
			korzinka()->arg = *args;
			return ;
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
