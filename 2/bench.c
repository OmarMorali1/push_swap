/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:45:00 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:11:06 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_name(int method)
{
	if (method == 0)
		return ("Simple / O(n^2)");
	if (method == 1)
		return ("Medium / O(n sqrt(n))");
	if (method == 2)
		return ("Complex / O(n log n)");
	return ("Adaptive / O(n sqrt(n))");
}

static void	print_bench2(t_bench *b)
{
	put_str_fd(" rb: ", 2);
	put_nbr_fd(b->rb, 2);
	put_str_fd(" rr: ", 2);
	put_nbr_fd(b->rr, 2);
	put_str_fd(" rra: ", 2);
	put_nbr_fd(b->rra, 2);
	put_str_fd(" rrb: ", 2);
	put_nbr_fd(b->rrb, 2);
	put_str_fd(" rrr: ", 2);
	put_nbr_fd(b->rrr, 2);
	put_str_fd("\n", 2);
}

void	print_bench(t_bench *b, double disord, int method)
{
	int	total;

	total = b->sa + b->sb + b->ss + b->pa + b->pb
		+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr;
	put_str_fd("[bench] disorder: ", 2);
	put_double_fd(disord * 100, 2);
	put_str_fd("%\n[bench] strategy: ", 2);
	put_str_fd(get_strategy_name(method), 2);
	put_str_fd("\n[bench] total_ops: ", 2);
	put_nbr_fd(total, 2);
	put_str_fd("\n[bench] sa: ", 2);
	put_nbr_fd(b->sa, 2);
	put_str_fd(" sb: ", 2);
	put_nbr_fd(b->sb, 2);
	put_str_fd(" ss: ", 2);
	put_nbr_fd(b->ss, 2);
	put_str_fd(" pa: ", 2);
	put_nbr_fd(b->pa, 2);
	put_str_fd(" pb: ", 2);
	put_nbr_fd(b->pb, 2);
	put_str_fd("\n[bench] ra: ", 2);
	put_nbr_fd(b->ra, 2);
	print_bench2(b);
}
