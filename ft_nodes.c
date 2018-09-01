/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:16:32 by ybokina           #+#    #+#             */
/*   Updated: 2018/09/01 13:16:39 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg			*ft_create_arg(char *name)
{
	t_arg *new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	new->name = ft_strdup(name);
	new->click = 0;
	new->on = 0;
	new->next = NULL;
	return (new);
}

t_arg			*ft_add_arg(t_arg **lst, char *name)
{
	t_arg *new_node;
	t_arg *last;

	if (!(new_node = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	last = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		return (new_node);
	}
	new_node->name = ft_strdup(name);
	new_node->click = 0;
	new_node->on = 0;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return (*lst);
}

t_arg			*argv_init(char **argv)
{
	t_arg	*new;
	int		i;

	i = 1;
	new = NULL;
	while (argv[i])
	{
		if (new == NULL)
			new = ft_create_arg(argv[i]);
		else
			new = ft_add_arg(&new, argv[i]);
		i++;
	}
	return (new);
}
