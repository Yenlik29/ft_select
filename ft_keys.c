/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:05:15 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/06 18:05:21 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg			*make_cycle(t_arg *lst, int i)
{
	int l;
	t_arg *head;
	t_arg *tmp;

	l = 0;
	head = lst;
	tmp = lst;
	while (tmp)
	{
		if (l < i)
		{
			l++;
			tmp = tmp->next;
		}
		if (l == i)
		{
			printf("*\n");
			// tmp->next = head;
			// head->prev = tmp;
		}
	}
	return (lst);
}

void			ft_del(t_arg **args)
{
	t_arg *tmp;
	t_arg *del;

	del = NULL;
	tmp = *args;
	while (tmp)
	{
		if (tmp->on == 1)
		{
			del = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	if (*args == NULL || del == NULL)
		return ;
	if (*args == del) //начальный нод
	{
		(*args)->on = 0;
		*args = del->next;
		printf("*\n");
	}
	if (del->next != NULL) //средний нод
	{
		del->next->on = 0;
		del->next->prev = del->prev;
		del->next->prev->on = 1;
		printf("!\n");
		korzinka()->arg = *args;
	}
	if (del->prev != NULL) //последний нод
	{
		del->prev->on = 0;
		del->prev->next = del->next;
		del->prev->next->on = 1;
		printf("-\n");
	}
	free(del);
	korzinka()->arg = *args;
}
