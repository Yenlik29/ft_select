/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:50:34 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/11 19:50:42 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_color(mode_t st_mode)
{
	S_ISBLK(st_mode) ? ft_putstr(C_RED) : NULL;
	S_ISCHR(st_mode) ? ft_putstr(C_GREEN) : NULL;
	S_ISDIR(st_mode) ? ft_putstr(C_PINK) : NULL;
	S_ISFIFO(st_mode) ? ft_putstr(C_BLUE) : NULL;
	S_ISREG(st_mode) ? ft_putstr(C_WHITE) : NULL;
	S_ISLNK(st_mode) ? ft_putstr(C_CYAN) : NULL;
	S_ISSOCK(st_mode) ? ft_putstr(C_MAGENTA) : NULL;
	(st_mode & S_IXUSR && !S_ISDIR(st_mode)) ? ft_putstr(C_RED) : NULL;
}

void			print_beauty_start()
{
	ft_putstr_fd(C_PINK, 1);
	ft_putstr_fd("Greetings, dear friend! ", 1);
	ft_putstr_fd("Here is your choice:\n", 1);
	ft_putstr_fd("\033[5m", 1);
	ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
	ft_putstr_fd(C_NONE, 1);
}

void			enter(t_arg **args)
{
	t_arg 	*tmp;
	t_arg	*new;

	new = NULL;
	tmp = *args;
	while (tmp)
	{
		if (tmp->click == 1)
		{
			if (new == NULL)
				new = ft_create_arg(tmp->name);
			else
				new = ft_add_arg(new, tmp->name);
		}
		tmp = tmp->next;
	}
	reset_original();
	if (new != NULL)
	{
		print_beauty_start();
		print_list(new);
		ft_putstr_fd("\033[5m", 1);
		ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
		ft_putstr_fd(C_NONE, 1);
	}
	else
	{
		ft_putstr_fd(C_PINK, 1);
		ft_putstr_fd("You didn't choose anything, my friend:(\n", 1);
		ft_putstr_fd(C_NONE, 1);
	}
	exit(0);
}