/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:44 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 16:55:32 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	buket_count(int len)
{
	int	l;
	int	r;
	int	mid;

	l = 0;
	r = len + 1;
	while (r > l + 1)
	{
		mid = (l + r) / 2;
		if (mid * mid <= len)
			l = mid;
		else
			r = mid;
	}
	return (l);
}

void	push_buket(t_stack **a, t_stack **b, int bounds[2], t_bench *bench)
{
	int	r;
	int	i;
	int	len;

	len = stack_len(*a);
	r = bounds[1] - bounds[0];
	i = 0;
	while (*a && i < len && r > 0)
	{
		if ((*a)->index >= bounds[0] && (*a)->index < bounds[1])
		{
			pb(a, b, bench);
			len--;
			r--;
			i = 0;
		}
		else
		{
			ra(a, bench);
			i++;
		}
	}
}

void	andary(t_stack **a, t_stack **b, int len, t_bench *bench)
{
	int	i;
	int	count;
	int	bounds[2];

	i = 0;
	count = buket_count(len);
	while (i < count)
	{
		bounds[0] = i * len / count;
		bounds[1] = (i + 1) * len / count;
		push_buket(a, b, bounds, bench);
		i++;
	}
}

void	push_b_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	len;

	while (*b)
	{
		pos = get_max_pos(*b);
		len = stack_len(*b);
		if (pos == 0)
			pa(a, b, bench);
		else if (pos <= len / 2)
			rb(b, bench);
		else
			rrb(b, bench);
	}
}

void	buket_sort(t_stack **a, t_bench *bench)
{
	int		len;
	t_stack	*b;

	len = stack_len(*a);
	if (len < 2)
		return ;
	b = NULL;
	andary(a, &b, len, bench);
	push_b_to_a(a, &b, bench);
}
