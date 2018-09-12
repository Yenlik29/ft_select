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

int				find_row(t_arg *args, int j)
{
	int 	col;
	int 	count;
	int		col_q;
	int 	row;
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

int				parse(mode_t st_mode)
{
	int valid;

	valid = 0;
	S_ISBLK(st_mode) ? valid = 1 : valid;
	S_ISCHR(st_mode) ? valid = 1 : valid;
	S_ISDIR(st_mode) ? valid = 1 : valid;
	S_ISFIFO(st_mode) ? valid = 1 : valid;
	S_ISREG(st_mode) ? valid = 1 : valid;
	S_ISLNK(st_mode) ? valid = 1: valid;
	S_ISSOCK(st_mode) ? valid = 1: valid;
	(st_mode & S_IXUSR && !S_ISDIR(st_mode)) ? valid = 1 : valid;
	return (valid);
}

int				find_act(t_arg *args, int col_q)
{
	int		row;
	int		j;
	int		col;
	t_arg 	*tmp;

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

void			print_more(t_arg *args, int col_q, struct winsize sz)
{
	int				i;
	int				c;
	int				dif;
	t_arg			*tmp;
	struct winsize	nw;

	c = col_q;
	tmp = args;
	i = find_act(tmp, col_q);
	ioctl(0, TIOCGWINSZ, &nw);
	while (tmp && --sz.ws_row)
	{
		if (tmp)
		{
			col_q = c;
			while (col_q--)
			{
				settings_on(tmp);
				// if (parse(tmp->st_mode) == 1)
					// ft_color(tmp->st_mode);
				ft_putstr_fd(tmp->name, 1);
				ft_putstr_fd(C_NONE, 1);
				settings_off(tmp);
				if (max_strlen(args) >= (int)ft_strlen(tmp->name))
					dif = max_strlen(args) - (int)ft_strlen(tmp->name);
				print_dif(dif);
				ft_putstr_fd(" ", 1);
				tmp = tmp->next;
			}
			ft_putstr_fd("\n", 1);
		}
	}
	ft_putstr_fd("...", 1);
	if ((i > nw.ws_row - 1) && (i <= korzinka()->i) && tmp)
		print_display(tmp);
}

void			print_dif(int dif)
{
	while (dif)
	{
		ft_putstr_fd(" ", 1);
		dif--;
	}
}

void			settings_on(t_arg *tmp)
{
	if (tmp->click == 1)
		tputs(tgetstr("mr", NULL), 1, re_putchar);
	if (tmp->click == 0)
		ft_putstr_fd(C_NONE, 1);
	if (tmp->on == 1)
		tputs(tgetstr("us", 0), 1, re_putchar);
}

void			settings_off(t_arg *tmp)
{
	if (tmp->on == 1)
		tputs(tgetstr("me", 0), 1, re_putchar);
	if (tmp->click == 1)
		ft_putstr_fd(C_NONE, 1);
}

void			print_norm(t_arg *args, int col_q)
{
	int				i;
	int 			dif;
	int				col;
	t_arg 			*tmp;
	struct winsize	sz;

	i = 0;
	col = col_q;
	tmp = args;
	ioctl(0, TIOCGWINSZ, &sz);
	while (tmp && i++ <= sz.ws_row)
	{
		col_q = col;
		while (col_q--)
		{
			if (tmp)
			{
				settings_on(tmp);
				// if (parse(tmp->st_mode) == 1)
					// ft_color(tmp->st_mode);
				ft_putstr_fd(tmp->name, 1);
				ft_putstr_fd(C_NONE, 1);
				settings_off(tmp);
				if (max_strlen(args) >= (int)ft_strlen(tmp->name))
					dif = max_strlen(args) - (int)ft_strlen(tmp->name);
				print_dif(dif);
				tmp = tmp->next;
				ft_putstr_fd(" ", 1);
			}
		}
		if (i != sz.ws_row)
			ft_putstr_fd("\n", 1);
	}
}

