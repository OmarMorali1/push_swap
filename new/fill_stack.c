/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:59:18 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

t_stack	*new_node(int val)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (0);
	new->value = val;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (!*a)
	{
		*a = new;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
}

static int	add_number(t_stack **a, char *str)
{
	long long	x;
	t_stack		*new;

	if (!valid_num(str))
		return (0);
	x = ft_atoll(str);
	if (x > 2147483647 || x < -2147483648)
		return (0);
	if (has_duplicate(*a, (int)x))
		return (0);
	new = new_node((int)x);
	if (!new)
		return (0);
	stack_add_back(a, new);
	return (1);
}

int	fill_stack_a(t_stack **a, char **argv, int start)
{
	int		i;
	int		j;
	char	**split_arg;

	i = start - 1;
	while (argv[++i])
	{
		split_arg = ft_split(argv[i], ' ');
		if (!split_arg || !split_arg[0])
		{
			free_split(split_arg);
			return (0);
		}
		j = -1;
		while (split_arg[++j])
		{
			if (!add_number(a, split_arg[j]))
			{
				free_split(split_arg);
				return (0);
			}
		}
		free_split(split_arg);
	}
	return (1);
}
