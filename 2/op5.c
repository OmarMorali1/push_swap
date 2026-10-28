/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:37 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 12:18:38 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_num(char *str)
{
	int	i;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
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
		i++;
	}
	return (res * s);
}

int	is_int(char *str)
{
	long long	x;

	x = ft_atoll(str);
	if (x < -2147483648LL || x > 2147483647LL)
		return (0);
	return (1);
}
