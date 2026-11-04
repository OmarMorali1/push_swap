/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *a, int val)
{
	while (a)
	{
		if (a->value == val)
			return (1);
		a = a->next;
	}
	return (0);
}

long long	ft_atoll(char *str)
{
	long long	res;
	int			s;
	int			i;

	res = 0;
	s = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483648LL)
			break ;
		i++;
	}
	return (res * s);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*cur;

	len = 0;
	cur = stack;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
