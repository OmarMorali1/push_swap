/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:46 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 16:55:36 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_bench *b)
{
	int	tmp;

	if (a == 0 || *a == 0 || (*a)->next == 0)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	write(1, "sa\n", 3);
	if (b && b->active)
		b->sa++;
}

void	sb(t_stack **b, t_bench *bench)
{
	int	tmp;

	if (b == 0 || *b == 0 || (*b)->next == 0)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	write(1, "sb\n", 3);
	if (bench && bench->active)
		bench->sb++;
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa(a, NULL);
	sb(b, NULL);
	write(1, "ss\n", 3);
	if (bench && bench->active)
		bench->ss++;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (b == 0 || *b == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	if (bench && bench->active)
		bench->pa++;
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (a == 0 || *a == 0)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
	if (bench && bench->active)
		bench->pb++;
}
