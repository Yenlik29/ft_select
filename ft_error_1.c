/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:53:53 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/25 17:53:59 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_error_tcgetattr(void)
{
	ft_putstr_fd("tcgetattr() error\n", 2);
}

void			ft_error_termdef(char *termtype)
{
	ft_putstr_fd("Terminal type ", 2);
	ft_putstr_fd(termtype, 2);
	ft_putstr_fd("is not defined.\n", 2);
}

void			ft_error_term_access()
{
	ft_putstr_fd("Could not access the termcap database.\n", 2);
}

void			ft_error_noterm()
{
	ft_putstr_fd("Specify a terminal type with `setenv TERM <yourtype>`.\n", 2);
}

void			ft_error_quantity()
{
	ft_putstr_fd("ft_select: wrong argument quantity.\n", 2);
}
