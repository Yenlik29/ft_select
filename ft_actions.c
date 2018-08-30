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

int				count_r_c(int WML, int CP)
{
	int N;

	N = WML + (CP * 4);
	return (N);
}

int				max_l(char	**argv)
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
