/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 16:15:32 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int len)
{
	int	l;
	int	r;
	int	mid;

	l = 0;
	r = len + 1;
	while (r > l + 1)
	{
		mid = (l + r) / 2;
		if (mid <= len / mid)
			l = mid;
		else
			r = mid;
	}
	if (l < 1 && len > 0)
		return (1);
	return (l);
}

static void	push_chunk(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	cnt;
	int	chunksize;

	cnt = 0;
	chunksize = chunk_size(size);
	while (*a)
	{
		if ((*a)->index <= cnt)
		{
			pb(a, b, bench);
			rb(b, bench, 1);
			cnt++;
		}
		else if ((*a)->index <= cnt + chunksize)
		{
			pb(a, b, bench);
			cnt++;
		}
		else
			ra(a, bench, 1);
	}
}

static int	max_pos(t_stack *b)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*tmp;

	max = -1;
	pos = 0;
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	push_b_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	len;

	while (*b)
	{
		pos = max_pos(*b);
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
		pa(a, b, bench);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	len;

	len = stack_len(*a);
	if (len <= 5)
	{
		small_sort(a, b, bench);
		return ;
	}
	index_stack(*a);
	push_chunk(a, b, len, bench);
	push_b_to_a(a, b, bench);
}
