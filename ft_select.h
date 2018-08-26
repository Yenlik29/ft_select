/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:39:57 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/25 11:40:35 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT
# include	<unistd.h>
# include	<stdio.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<termios.h>
# include	<string.h>
# include	<stdlib.h>
# include	<termcap.h>
# include	<term.h>
# include	"libft/libft.h"

int				terminal_init(char **argv);

void			ft_error_quantity();
void			ft_error_noterm();
void			ft_error_term_access();
void			ft_error_termdef(char *termtype);

#endif
