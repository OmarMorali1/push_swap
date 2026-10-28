/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:52 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:04:53 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max_val;

	if (size <= 1)
		return (0);
	max_val = size - 1;
	bits = 0;
	while ((max_val >> bits) != 0)
		bits++;
	return (bits);
}

void	hard_radix_sort(t_stack **a, int size, t_bench *bench)
{
	int		v[3];
	t_stack	*b;

	b = NULL;
	v[2] = get_max_bits(size);
	v[0] = 0;
	while (v[0] < v[2])
	{
		v[1] = 0;
		while (v[1] < size)
		{
			if (((*a)->index >> v[0]) & 1)
				ra(a, bench);
			else
				pb(a, &b, bench);
			v[1]++;
		}
		while (b)
			pa(a, &b, bench);
		v[0]++;
	}
}
