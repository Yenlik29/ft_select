/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:45:28 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/27 13:45:35 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_error_isatty(void)
{
	ft_putstr_fd("isatty() error\n", 2);
}

void			ft_error_tcsetattr(void)
{
	ft_putstr_fd("tcsetattr() error\n", 2);
}
