/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b, int mode, t_bench *bench)
{
	bench->disord = disorder(*a);
	if (mode == 0)
		selection_sort(a, b, bench);
	else if (mode == 1)
		chunk_sort(a, b, bench);
	else if (mode == 2)
		turk_sort(a, b, bench);
	else if (bench->disord < 0.2)
		selection_sort(a, b, bench);
	else if (bench->disord < 0.5)
		chunk_sort(a, b, bench);
	else
		turk_sort(a, b, bench);
}

static int	print_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(&a);
	return (1);
}

static void	free_all(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		method;
	int		start;

	if (argc < 2)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	a = NULL;
	b = NULL;
	start = parse_flags(argc, argv, &bench, &method);
	if (start == -1 || start >= argc)
		return (print_error(a));
	if (!fill_stack_a(&a, argv, start))
		return (print_error(a));
	if (!is_sorted(a))
		sort(&a, &b, method, &bench);
	if (bench.active)
		print_bench(&bench, method);
	free_all(&a, &b);
	return (0);
}
