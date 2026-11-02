/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 4))
		sa(a, NULL, 0);
	else if (!ft_strncmp(op, "sb\n", 4))
		sb(b, NULL, 0);
	else if (!ft_strncmp(op, "ss\n", 4))
		ss(a, b, NULL);
	else if (!ft_strncmp(op, "pa\n", 4))
		pa(a, b, NULL);
	else if (!ft_strncmp(op, "pb\n", 4))
		pb(a, b, NULL);
	else if (!ft_strncmp(op, "ra\n", 4))
		ra(a, NULL, 0);
	else if (!ft_strncmp(op, "rb\n", 4))
		rb(b, NULL, 0);
	else if (!ft_strncmp(op, "rr\n", 4))
		rr(a, b, NULL);
	else if (!ft_strncmp(op, "rra\n", 5))
		rra(a, NULL, 0);
	else if (!ft_strncmp(op, "rrb\n", 5))
		rrb(b, NULL, 0);
	else if (!ft_strncmp(op, "rrr\n", 5))
		rrr(a, b, NULL);
	else
		return (0);
	return (1);
}

static int	read_operations(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(a, b, line))
		{
			free(line);
			write(2, "Error\n", 6);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ret;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!fill_stack_a(&a, argv, 1))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	ret = read_operations(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (ret);
}
