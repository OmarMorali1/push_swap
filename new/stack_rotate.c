/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ra(t_stack **a, t_bench *bench, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
	if (bench && bench->active && print)
		bench->ra++;
}

void	rb(t_stack **b, t_bench *bench, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
	if (bench && bench->active && print)
		bench->rb++;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a, NULL, 0);
	rb(b, NULL, 0);
	if (bench)
	{
		write(1, "rr\n", 3);
		if (bench->active)
			bench->rr++;
	}
}
