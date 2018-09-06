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

int				struct_col(t_arg *args)
{
	int i;
	t_arg *s;

	i = 0;
	s = args;
	while (s != NULL)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int 			get_row(int col_q, int q)
{
	int row_q;

	row_q = 1;
	if (q % col_q != 0)
		row_q = ((q / col_q) + 1);
	else
		row_q = (q / col_q);
	return (row_q);
}

t_arg			*ft_create_arg(char *name)
{
	t_arg *new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	new->name = ft_strdup(name);
	new->click = 0;
	new->on = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_arg			*ft_add_arg(t_arg *lst, char *name)
{
	t_arg *new_node;
	t_arg *temp;

	if (!(new_node = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	temp = lst;
	if (lst == NULL)
	{
		lst = new_node;
		return (new_node);
	}
	new_node->name = ft_strdup(name);
	new_node->click = 0;
	new_node->on = 0;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (lst);
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
			new = ft_add_arg(new, argv[i]);
		i++;
	}
	// new = make_cycle(new, i);
	return (new);
}
