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
	t_arg 	*tmp;

	count = 0;
	tmp = *args;
	while (tmp)
	{
		if (tmp->click == 1)
		{
			if (tmp->on == 1)
			{
				tmp->click = 0;
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
		}
		else if (tmp->click == 0)
		{
			if (tmp->on == 1)
			{
				tmp->click = 1;
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
		}
		tmp = tmp->next;
	}
}

void			ft_up(t_arg **args)
{
	int				count;
	t_arg			*tmp;
	struct winsize	sz;
	int				i;
	int				max_s;
	int				col_q;
	t_arg			*lst;

	i = 1;
	count = 0;
	lst = *args;
	tmp = *args;
	max_s = max_strlen(*args);
	ioctl(0, TIOCGWINSZ, &sz);
	col_q = get_col(sz, max_s);
	while (tmp)
	{
		if (tmp->on == 1)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		if (find_row(lst, i) == 1)
		{
			tmp->on = 0;
			if ((korzinka()->i - 1) * col_q + i > korzinka()->quant)
			{
				while (tmp->next)
					tmp = tmp->next;
				tmp->on = 1;
				korzinka()->arg = *args;
				return ;
			}
			else
			{
				while (count != ((korzinka()->i - 1) * col_q))
				{
					tmp = tmp->next;
					count++;
				}
			}
			tmp->on = 1;
			korzinka()->arg = *args;
			return ;
		}
		else
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

int				find(t_arg *lst, int col_q, int i)
{
	int	begin;
	int	col;
	t_arg *tmp;

	col = 0;
	begin = 0;
	tmp = lst;
	begin = (find_row(lst, i) - 1) * col_q;
	begin++;
	col = i - begin;
	return (col);
}

void			ft_down(t_arg **args)
{
	int				i;
	t_arg			*tmp;
	t_arg			*lst;
	int				count;
	struct winsize	sz;
	int				max_s;
	int				col_q;
	int				col;

	i = 1;
	count = 0;
	col = 0;
	tmp = *args;
	lst = *args;
	ioctl(0, TIOCGWINSZ, &sz);
	max_s = max_strlen(*args);
	col_q = get_col(sz, max_s);
	while (tmp)
	{
		if (tmp->on == 1)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		if (find_row(lst, i) == korzinka()->i)
		{
			col = find(lst, col_q, i);
			tmp->on = 0;
			while (i-- != 1)
				tmp = tmp->prev;
			while (i++ != col)
				tmp = tmp->next;
			tmp->on = 1;
			korzinka()->arg = *args;
			return ;
		}
		else
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
