/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:02:05 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/26 13:41:00 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (a == 0 || *a == 0 || (*a)->next == 0)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = 0;
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (b == 0 || *b == 0 || (*b)->next == 0)
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = 0;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
