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
	// struct termios original;
	int key;

	while (1)
	{
		read(0, &key, 8);
		printf("%d\n", key);
		if (key == 32539)
		{
			// tcgetattr(0, &original);
			// original.c_lflag |= ICANON;
			// original.c_lflag |= ECHO;
			// original.c_cc[VMIN] = 1;
			// tcsetattr(0, TCSANOW, &original);
			// tputs(tgetstr("te", 0), 1, re_putchar);
			// tputs(tgetstr("ve", 0), 1, re_putchar);
			// printf(">suspended - need to work on it (fg)\n");
			// signal(SIGTSTP, SIG_DFL);
			exit(0);
		}
		if (key == 4283163)
			printf("UP!\n");
		if (key == 4348699)
			printf("DOWN!\n");
		if (key == 4414235)
			printf("RIGHT!\n");
		if (key == 4479771)
			printf("LEFT!\n");
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
