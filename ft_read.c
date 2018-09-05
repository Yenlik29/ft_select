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

int 			read_input()
{
	int key;

	key = 0;
	printf("%d\n", key);
	return (1);
}

// char 				*read_input()
// {
// 	char ch;
// 	int sz;
// 	char *word;

// 	word = ft_strnew(4096);
// 	printf("\n");
// 	while ((sz = read(0, &ch, 1)) > 0)
// 	{
// 		printf("*\n");
// 		if (ch == 27)
// 			printf("yes\n");
// 		else
// 			printf("!\n");
// 		word = ft_strncat(word, &ch, 1);
// 	}
// 	return (word);
// }
