/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:55 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 16:55:47 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_stack *stack)
{
	int		min_val;
	int		min_pos;
	int		curr_pos;
	t_stack	*curr;

	if (!stack)
		return (-1);
	min_val = stack->value;
	min_pos = 0;
	curr_pos = 0;
	curr = stack;
	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = curr_pos;
		}
		curr = curr->next;
		curr_pos++;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *b)
{
	int		mx;
	int		pos;
	int		i;
	t_stack	*tmp;

	if (!b)
		return (-1);
	mx = b->index;
	pos = 0;
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > mx)
		{
			mx = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	bring_min_to_top(t_stack **a, t_bench *b)
{
	int	pos;
	int	size;
	int	from_bottom;

	if (!a || !*a)
		return ;
	size = stack_len(*a);
	pos = get_min_position(*a);
	from_bottom = size - pos;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, b);
			pos--;
		}
	}
	else
	{
		while (from_bottom > 0)
		{
			rra(a, b);
			from_bottom--;
		}
	}
}

void	easy_sort(t_stack **a, t_bench *bench)
{
	t_stack	*b;
	int		size;

	if (!a || !*a)
		return ;
	b = NULL;
	size = stack_len(*a);
	while (size > 1)
	{
		bring_min_to_top(a, bench);
		pb(a, &b, bench);
		size--;
	}
	while (b)
		pa(a, &b, bench);
}
