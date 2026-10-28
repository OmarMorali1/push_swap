/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:48 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 12:18:49 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n)
	{
		*p = c;
		n --;
		p ++;
	}
	return (s);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;
	size_t	res_size;

	res_size = n * size;
	if (n != 0 && res_size / n != size)
		return (NULL);
	res = malloc(res_size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, res_size);
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
