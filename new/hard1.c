/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	final_alignment(t_stack **a, t_bench *bench)
{
	t_stack	*curr;
	int		min_pos;
	int		len;

	curr = *a;
	min_pos = 0;
	len = stack_len(*a);
	while (curr && curr->index != 0)
	{
		curr = curr->next;
		min_pos++;
	}
	if (min_pos <= len / 2)
	{
		while (min_pos-- > 0)
			ra(a, bench, 1);
	}
	else
	{
		while (min_pos++ < len)
			rra(a, bench, 1);
	}
}

static void	push_all_save_three(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = stack_len(*a);
	while (size > 3)
	{
		pb(a, b, bench);
		size--;
	}
}

void	turk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	len;

	len = stack_len(*a);
	if (len <= 5)
	{
		selection_sort(a, b, bench);
		return ;
	}
	index_stack(*a);
	push_all_save_three(a, b, bench);
	sort_three(a, bench);
	push_back_to_a(a, b, bench);
	final_alignment(a, bench);
}
