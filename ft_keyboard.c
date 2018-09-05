/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:26:48 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/30 19:26:57 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			key_init()
{
	// int		nread;
	char	*ch;
	int 	k;

	k = 0;
	while (1)
	{
		ch = read_input();
		printf("->%s\n", ch);
		// nread = read_input();
	}
}

void			print_list(t_arg *lst)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

t_link 			*korzinka(void)
{
	static t_link tmp;

	return (&tmp);
}

int				get_col(struct winsize sz, int max_s)
{
	if ((sz.ws_col - 2) % (max_s + 2) != 0)
		return ((sz.ws_col - 2) / (max_s + 2));
	else
		return ((sz.ws_col - 2) / ((max_s + 2) - 1));
}

void			print_display(t_arg *args)
{
	struct winsize	sz;
	int 			max_s;
	int 			col_q;
	int				row_q;
	int 			q;

	ioctl(0, TIOCGWINSZ, &sz);
	tputs(tgetstr("cl", NULL), 1, re_putchar);
	max_s = max_strlen(args);
	if (((max_s + 2) > (sz.ws_col - 4)) || (sz.ws_row < 1))
	{
		tputs(tgetstr("cl", NULL), 1, re_putchar);
		ft_error_display_size();
		return ;
	}
	q = struct_col(args);
	col_q = get_col(sz, max_s);
	row_q = get_row(col_q, q);
	if (row_q > sz.ws_row)
		print_more(args, col_q, sz);
	else
		print_norm(args, row_q, col_q);
	//print_list(args);
}
