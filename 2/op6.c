/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:39 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:04:44 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_num(int argc, char **argv)
{
	char	**num;

	if (argc < 2)
		return (0);
	if (argc == 2)
		num = ft_split(argv[1], ' ');
	else
		num = &argv[1];
	return (num);
}

void	freesplit(char **str)
{
	int	i;

	if (str == 0)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	add_number(t_stack **a, char *str)
{
	long long	x;
	t_stack		*new;

	if (!valid_num(str) || !is_int(str))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		return (1);
	}
	x = ft_atoll(str);
	new = stack_new((int)x);
	if (new == 0)
	{
		free_stack(a);
		return (1);
	}
	stack_add_back(a, new);
	return (0);
}

int	is_sort(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	parse_args(int argc, char **argv, int *start, t_bench *bench)
{
	int	i;
	int	method;

	i = 1;
	method = 3;
	while (i < argc && i <= 2)
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
		{
			bench->active = 1;
			(*start)++;
		}
		else if (get_method(argv[i]) != -1)
		{
			method = get_method(argv[i]);
			(*start)++;
		}
		i++;
	}
	return (method);
}
