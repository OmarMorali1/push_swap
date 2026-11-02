/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_chunk_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 19:05:11 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 19:13:17 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *b)
{
	int	pos;
	int	max_pos;
	int	max;

	pos = 0;
	max_pos = 0;
	max = b->index;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

static void	move_max_to_top(t_stack **b, t_bench *bench)
{
	int	pos;
	int	len;

	pos = get_max_pos(*b);
	len = stack_len(*b);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			rb(b, bench, 1);
	}
	else
	{
		while (pos++ < len)
			rrb(b, bench, 1);
	}
}

static void	push_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	while (*a)
	{
		if (!*b || (*a)->index > (*b)->index)
			pb(a, b, bench);
		else
		{
			move_max_to_top(b, bench);
			pb(a, b, bench);
		}
	}
}

void	small_chunk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	push_to_b(a, b, bench);
	while (*b)
		pa(a, b, bench);
}
