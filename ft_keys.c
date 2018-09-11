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
			tmp->next = head;
			head->prev = tmp;
		}
	}
	return (lst);
}

int				where(t_arg **args)
{
	int		i;
	t_arg 	*tmp;

	i = 1;
	tmp = *args;
	while (tmp)
	{
		if (tmp->on == 1)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void			deleteNode(t_arg **head, t_arg *del)
{
	if (*head == NULL || del == NULL)
		return ;
	if (*head == del && del->next)
	{
		*head = del->next;
		del->next->on = 1;
		del->next->prev = NULL;
	}
	if (del->prev != NULL && del->next != NULL)
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
		del->next->on = 1;
	}
	if (del->prev != NULL && del->next == NULL)
	{
		del->prev->next = NULL;
		(*head)->on = 1;
	}
	free(del);
}

void			ft_del(t_arg **args)
{
	int		i;
	int		n;
	t_arg 	*cur;

	if (*args == NULL)
		return ;
	i = 1;
	cur = *args;
	n = where(args);
	while ((cur != NULL) && (i < n))
	{
		i++;
		cur = cur->next;
	}
	if (quantity(*args) == 1)
	{
		reset_original();
		exit(0);
	}
	if (!cur)
		return ;
	deleteNode(args, cur);
}
