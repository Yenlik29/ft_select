/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:38:29 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/05 14:38:39 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// int 			read_input()
// {
// 	int 	ret;
// 	char	*key;
// 	char 	buf[100];

// 	key = (char *)malloc(sizeof(char) * 2048);
// 	if (((ret = read(0, buf, 8)) > 0) && (*buf != '\n'))
// 	{
// 		// ft_putstr("|");
// 		// ft_putchar(buf);
// 		// ft_putstr("|");
// 		// ft_putstr("\n");
// 		key = ft_strncat(key, buf, 8);
// 		printf("|%s|\n", key);
// 		// ft_putnbr(ret);
// 		// buf[ret] = '\0';
// 		// ft_putstr("->");
// 		// ft_putstr(buf);
// 	}
// 	ft_bzero(key, ft_strlen(key));
// 	return (1);
// }

char 				*read_input()
{
	char ch;
	int sz;
	char *word;

	word = ft_strnew(4096);
	printf("\n");
	while ((sz = read(0, &ch, 1)) > 0)
	{
		printf("*\n");
		if (ch == 27)
			printf("yes\n");
		else
			printf("!\n");
		word = ft_strncat(word, &ch, 1);
	}
	return (word);
}

// int				read_input()
// {
// 	// char	k;
// 	char	buf[20];
// 	int		res;
// 	char	*key;

// 	res = 0;
// 	key = ft_strnew(100);
// 	ft_putstr("\n");
// 	if ((res = read(0, &buf, 8)) > 0)
// 	{
// 		buf[8] = '\0';
// 		key = ft_strncat(key, buf, 8);
// 		ft_putendl(key);
// 	}
// 	ft_bzero(key, ft_strlen(key));
// 	free(key);
// 	return (1);
// }
