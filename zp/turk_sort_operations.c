/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_cheapest_node(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->total_cost < cheapest->total_cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *node,
	t_bench *bench)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b, bench);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b, bench);
		node->cost_a++;
		node->cost_b++;
	}
}

static void	exec_rotations(t_stack **a, t_stack **b, t_stack *node,
	t_bench *bench)
{
	rotate_both(a, b, node, bench);
	while (node->cost_a > 0)
	{
		ra(a, bench, 1);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a, bench, 1);
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		rb(b, bench, 1);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b, bench, 1);
		node->cost_b++;
	}
}

void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*cheapest;

	while (*b)
	{
		calculate_and_set_costs(*a, *b);
		cheapest = get_cheapest_node(*b);
		exec_rotations(a, b, cheapest, bench);
		pa(a, b, bench);
	}
}
