/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	min_position(t_stack *a)
{
	int		min_val;
	int		min_pos;
	int		pos;
	t_stack	*curr;

	curr = a;
	min_val = a->value;
	min_pos = 0;
	pos = 0;
	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack **a, int min_pos, t_bench *b)
{
	int	size;

	size = stack_len(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, b, 1);
	}
	else
	{
		while (min_pos++ < size)
			rra(a, b, 1);
	}
}

void	small_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	while (stack_len(*a) > 3)
	{
		move_min_to_top(a, min_position(*a), bench);
		pb(a, b, bench);
	}
	if (!is_sorted(*a))
		sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}

void	selection_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	len;

	len = stack_len(*a);
	if (len < 2 || is_sorted(*a))
		return ;
	if (len == 2)
		sa(a, bench, 1);
	else
		small_sort(a, b, bench);
}
