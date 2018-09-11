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

void			print_beauty_start()
{
	ft_putstr("\033[01;38;05;181m");
	ft_putstr("Greetings, dear friend! ");
	ft_putstr("Here is your choice:\n");
	ft_putstr("\033[5m");
	ft_putstr("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_putstr(C_NONE);
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
	print_beauty_start();
	print_list(new);
	ft_putstr("\033[5m");
	ft_putstr("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_putstr(C_NONE);
	exit(0);
}