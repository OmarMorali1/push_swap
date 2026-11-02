/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_bench *b)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = (*a)->value;
	v2 = (*a)->next->value;
	v3 = (*a)->next->next->value;
	if (v1 > v2 && v2 > v3)
	{
		sa(a, b, 1);
		rra(a, b, 1);
	}
	else if (v1 > v2 && v1 > v3)
		ra(a, b, 1);
	else if (v1 > v2)
		sa(a, b, 1);
	else if (v2 > v3 && v1 > v3)
		rra(a, b, 1);
	else if (v2 > v3)
	{
		rra(a, b, 1);
		sa(a, b, 1);
	}
}
