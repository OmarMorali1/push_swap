/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:41:05 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/26 13:41:06 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int x)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (0);
	new->value = x;
	new->index = 0;
	new->next = 0;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == 0 || new == 0)
		return ;
	if (*stack == 0)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	duplicate(t_stack *a)
{
	t_stack	*cur1;
	t_stack	*cur2;

	cur1 = a;
	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cur1->value == cur2->value)
				return (1);
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (0);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (a == 0)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
