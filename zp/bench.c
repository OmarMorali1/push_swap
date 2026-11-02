/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_name(int method, double disord)
{
	if (method == 0)
		return ("Simple / O(n^2)");
	if (method == 1)
		return ("Medium / O(n\342\210\232n)");
	if (method == 2)
		return ("Complex / O(n log n)");
	if (disord < 0.2)
		return ("Adaptive / O(n^2)");
	if (disord < 0.5)
		return ("Adaptive / O(n\342\210\232n)");
	return ("Adaptive / O(n log n)");
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

static void	print_bench1(t_bench *b, int method)
{
	int	total;

	total = b->sa + b->sb + b->ss + b->pa + b->pb
		+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr;
	put_str_fd("[bench] disorder: ", 2);
	put_double_fd(b->disord * 100, 2);
	put_str_fd("%\n[bench] strategy: ", 2);
	put_str_fd(get_strategy_name(method, b->disord), 2);
	put_str_fd("\n[bench] total_ops: ", 2);
	put_nbr_fd(total, 2);
}

void	print_bench(t_bench *b, int method)
{
	print_bench1(b, method);
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
