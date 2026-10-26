/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:06:11 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/26 13:34:56 by ommorali         ###   ########.fr       */
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

void	hard_radix_sort(t_stack **a, t_stack **b, int size)
{
	int	v[3];

	v[2] = get_max_bits(size);
	v[0] = 0;
	while (v[0] < v[2])
	{
		v[1] = 0;
		while (v[1] < size)
		{
			if (((*a)->index >> v[0]) & 1)
				ra(a);
			else
				pb(a, b);
			v[1]++;
		}
		while (*b)
			pa(a, b);
		v[0]++;
	}
}
// v[0] = bit_index, v[1] = j (counter), v[2] = max_bits