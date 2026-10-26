/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:41:02 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/26 13:41:03 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (a == 0 || *a == 0 || (*a)->next == 0)
		return ;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = 0;
	last->next = *a;
	*a = last;
}

void	rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (b == 0 || *b == 0 || (*b)->next == 0)
		return ;
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = 0;
	last->next = *b;
	*b = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
