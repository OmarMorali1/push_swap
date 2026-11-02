/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_method(char *str)
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

int	parse_flags(int argc, char **argv, t_bench *bench, int *method)
{
	int	i;
	int	curr;
	int	set;

	i = 1;
	set = 0;
	*method = 3;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			bench->active = 1;
		else
		{
			curr = get_method(argv[i]);
			if (curr == -1 || set)
				return (-1);
			*method = curr;
			set = 1;
		}
		i++;
	}
	return (i);
}
