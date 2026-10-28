/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:56 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 15:31:00 by ommorali         ###   ########.fr       */
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
		return (0);
	return ((double)mis / pair);
}
