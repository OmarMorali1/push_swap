/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	get_target_a_pos(t_stack *a, int b_index)
{
	t_stack	*curr;
	t_stack	*target;

	curr = a;
	target = NULL;
	while (curr)
	{
		if (curr->index > b_index && (!target || curr->index < target->index))
			target = curr;
		curr = curr->next;
	}
	if (!target)
	{
		target = a;
		curr = a->next;
		while (curr)
		{
			if (curr->index < target->index)
				target = curr;
			curr = curr->next;
		}
	}
	return (target->pos);
}

static void	set_positions(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s->pos = i;
		i++;
		s = s->next;
	}
}

static void	calculate_individual_costs(t_stack *node, int len_a, int len_b)
{
	if (node->pos <= len_b / 2)
		node->cost_b = node->pos;
	else
		node->cost_b = node->pos - len_b;
	if (node->target_pos <= len_a / 2)
		node->cost_a = node->target_pos;
	else
		node->cost_a = node->target_pos - len_a;
}

static void	calculate_total_cost(t_stack *node)
{
	int	ca;
	int	cb;

	ca = node->cost_a;
	cb = node->cost_b;
	if ((ca >= 0 && cb >= 0) || (ca <= 0 && cb <= 0))
	{
		node->total_cost = ft_abs(ca);
		if (ft_abs(cb) > node->total_cost)
			node->total_cost = ft_abs(cb);
	}
	else
		node->total_cost = ft_abs(ca) + ft_abs(cb);
}

void	calculate_and_set_costs(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	set_positions(a);
	set_positions(b);
	curr_b = b;
	while (curr_b)
	{
		curr_b->target_pos = get_target_a_pos(a, curr_b->index);
		calculate_individual_costs(curr_b, len_a, len_b);
		calculate_total_cost(curr_b);
		curr_b = curr_b->next;
	}
}
