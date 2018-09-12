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

// void			ft_color(mode_t st_mode)
// {
// 	S_ISBLK(st_mode) ? ft_putstr_fd(C_RED) : NULL;
// 	S_ISCHR(st_mode) ? ft_putstr_fd(C_GREEN) : NULL;
// 	S_ISDIR(st_mode) ? ft_putstr_fd(C_PINK) : NULL;
// 	S_ISFIFO(st_mode) ? ft_putstr_fd(C_BLUE) : NULL;
// 	S_ISREG(st_mode) ? ft_putstr_fd(C_WHITE) : NULL;
// 	S_ISLNK(st_mode) ? ft_putstr_fd(C_CYAN) : NULL;
// 	S_ISSOCK(st_mode) ? ft_putstr_fd(C_MAGENTA) : NULL;
// 	(st_mode & S_IXUSR && !S_ISDIR(st_mode)) ? ft_putstr_fd(C_RED) : NULL;
// }

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
	print_list(new);
	exit(0);
}