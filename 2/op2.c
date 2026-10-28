/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:43 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:11:13 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_bench *b)
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
	write(1, "ra\n", 3);
	if (b && b->active)
		b->ra++;
}

void	rb(t_stack **b, t_bench *bench)
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
	write(1, "rb\n", 3);
	if (bench && bench->active)
		bench->rb++;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a, NULL);
	rb(b, NULL);
	write(1, "rr\n", 3);
	if (bench && bench->active)
		bench->rr++;
}

void	rra(t_stack **a, t_bench *b)
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
	write(1, "rra\n", 4);
	if (b && b->active)
		b->rra++;
}

void	rrb(t_stack **b, t_bench *bench)
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
	write(1, "rrb\n", 4);
	if (bench && bench->active)
		bench->rrb++;
}
