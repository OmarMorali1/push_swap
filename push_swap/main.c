/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:05:32 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/26 14:10:17 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	stack_builder(int argc, char **argv, char **num, t_stack **a)
{
	int		i;

	num = get_num(argc, argv);
	if (!num)
		return (0);
	i = 0;
	while (num[i])
	{
		if (add_number(a, num[i]))
		{
			if (argc == 2)
				freesplit(num);
			return (1);
		}
		i++;
	}
	if (argc == 2)
		freesplit(num);
	if (duplicate(*a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	char	**num;

	if (argc < 2)
		return (0);
	num = get_num(argc, argv);
	if (!num)
		return (0);
	a = 0;
	stack_builder(argc, argv, num, &a);
	if (is_sort(a))
	{
		free_stack(&a);
		return (0);
	}
	index_stack(a);
	tmp = a;
	while (tmp)
	{
		printf("value: %d | index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	hard_radix_sort(&a, &b, stack_len(a));
	printf("%s", "\n\n");
	tmp = a;
	while (tmp)
	{
		printf("value: %d | index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	free_stack(&a);
	return (0);
}
