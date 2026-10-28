/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:29:07 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 17:07:22 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	put_nbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		put_str_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		put_nbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	put_double_fd(double n, int fd)
{
	int	integer_part;
	int	decimal_part;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	integer_part = (int)n;
	decimal_part = (int)((n - integer_part) * 100 + 0.5);
	if (decimal_part >= 100)
	{
		integer_part += 1;
		decimal_part = 0;
	}
	put_nbr_fd(integer_part, fd);
	write(fd, ".", 1);
	if (decimal_part < 10)
		write(fd, "0", 1);
	put_nbr_fd(decimal_part, fd);
}
