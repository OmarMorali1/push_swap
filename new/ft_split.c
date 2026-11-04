/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:07:10 by ommorali          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:12 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static size_t	words_count(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static char	*word_dup(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_res(char **res, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		res[i] = word_dup(s, c);
		if (!res[i])
		{
			free_all(res, i);
			return (0);
		}
		i++;
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((words_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!fill_res(res, s, c))
		return (NULL);
	return (res);
}
