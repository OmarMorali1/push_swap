/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_bench *bench, int print)
{
	int	tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	if (print)
		write(1, "sa\n", 3);
	if (bench && bench->active && print)
		bench->sa++;
}

void	sb(t_stack **b, t_bench *bench, int print)
{
	int	tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	tmp = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = tmp;
	if (print)
		write(1, "sb\n", 3);
	if (bench && bench->active && print)
		bench->sb++;
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa(a, NULL, 0);
	sb(b, NULL, 0);
	if (bench)
	{
		write(1, "ss\n", 3);
		if (bench->active)
			bench->ss++;
	}
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (bench)
	{
		write(1, "pa\n", 3);
		if (bench->active)
			bench->pa++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (bench)
	{
		write(1, "pb\n", 3);
		if (bench->active)
			bench->pb++;
	}
}
