/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *a)
{
	int		mis;
	int		pair;
	t_stack	*i;
	t_stack	*j;

	mis = 0;
	pair = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pair++;
			if (i->value > j->value)
				mis++;
			j = j->next;
		}
		i = i->next;
	}
	if (pair == 0)
		return (0.0);
	return ((double)mis / pair);
}

void	index_stack(t_stack *a)
{
	t_stack	*curr;
	t_stack	*tmp;
	int		index;

	curr = a;
	while (curr)
	{
		index = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->value < curr->value)
				index++;
			tmp = tmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
