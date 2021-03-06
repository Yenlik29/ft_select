/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:18:20 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/27 20:18:28 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				max_strlen(t_arg *args)
{
	t_arg	*n;
	int		max;

	max = 0;
	n = args;
	while (n != NULL)
	{
		if (max < (int)ft_strlen(n->name))
			max = (int)ft_strlen(n->name);
		n = n->next;
	}
	return (max);
}

int				count_r_c(int wml, int space)
{
	int n;

	n = wml + (space * 4);
	return (n);
}

int				max_l(char **argv)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count = count + ft_strlen(argv[i]);
		i++;
	}
	return (count);
}

int				len(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
		i++;
	return (i - 1);
}

int				re_putchar(int ch)
{
	return (write(0, &ch, 1));
}
