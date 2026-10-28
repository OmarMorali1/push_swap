/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:50 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:15:14 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_builder2(int argc, t_stack **a, char **num)
{
	if (argc == 2)
		freesplit(num);
	if (duplicate(*a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		*a = NULL;
		return (1);
	}
	return (0);
}

static int	stack_builder1(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**num;

	num = get_num(argc, argv);
	if (!num)
		return (1);
	i = 0;
	while (num[i])
	{
		if (add_number(a, num[i]))
		{
			if (argc == 2)
				freesplit(num);
			free_stack(a);
			*a = NULL;
			return (1);
		}
		i++;
	}
	return (stack_builder2(argc, a, num));
}

int	get_method(char *str)
{
	if (!ft_strncmp(str, "--simple", 9))
		return (0);
	if (!ft_strncmp(str, "--medium", 9))
		return (1);
	if (!ft_strncmp(str, "--complex", 10))
		return (2);
	if (!ft_strncmp(str, "--adaptive", 11))
		return (3);
	return (-1);
}

static int	algo_manager(t_stack *a, int method, double disord, t_bench *bench)
{
	if (is_sort(a))
	{
		free_stack(&a);
		return (0);
	}
	index_stack(a);
	disord = disorder(a);
	if (method == 0)
		easy_sort(&a, bench);
	else if (method == 1)
		buket_sort(&a, bench);
	else if (method == 2)
		hard_radix_sort(&a, stack_len(a), bench);
	else if (disord < 0.2)
		easy_sort(&a, bench);
	else if (disord < 0.5)
		buket_sort(&a, bench);
	else
		hard_radix_sort(&a, stack_len(a), bench);
	if (bench->active)
		print_bench(bench, disord, method);
	free_stack(&a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_bench	bench;
	int		method;
	int		start;

	if (argc < 2)
		return (0);
	bench = (t_bench){0};
	start = 1;
	method = parse_args(argc, argv, &start, &bench);
	if ((start == 2 && argc < 3) || (start == 3 && argc < 4) || (method == -1))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = 0;
	if (stack_builder1(argc - start + 1, &argv[start - 1], &a))
		return (1);
	return (algo_manager(a, method, 0, &bench));
}
