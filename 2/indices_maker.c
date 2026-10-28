/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:18:51 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/28 12:18:52 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_subarrays(int *arr, int left, int *lr[2], int n[2])
{
	int	v[3];

	v[0] = 0;
	v[1] = 0;
	v[2] = left;
	while (v[0] < n[0] && v[1] < n[1])
	{
		if (lr[0][v[0]] <= lr[1][v[1]])
			arr[v[2]++] = lr[0][v[0]++];
		else
			arr[v[2]++] = lr[1][v[1]++];
	}
	while (v[0] < n[0])
		arr[v[2]++] = lr[0][v[0]++];
	while (v[1] < n[1])
		arr[v[2]++] = lr[1][v[1]++];
	free(lr[0]);
	free(lr[1]);
}
// v[0]=i, v[1]=j, v[2]=k

static void	merge(int *arr, int left, int mid, int right)
{
	int	v[4];
	int	*lr[2];

	v[0] = mid - left + 1;
	v[1] = right - mid;
	lr[0] = malloc(sizeof(int) * v[0]);
	lr[1] = malloc(sizeof(int) * v[1]);
	if (!lr[0] || !lr[1])
	{
		free(lr[0]);
		free(lr[1]);
		return ;
	}
	v[2] = -1;
	while (++v[2] < v[0])
		lr[0][v[2]] = arr[left + v[2]];
	v[3] = -1;
	while (++v[3] < v[1])
		lr[1][v[3]] = arr[mid + 1 + v[3]];
	merge_subarrays(arr, left, lr, v);
}
// v[0]=n1, v[1]=n2, v[2]=i, v[3]=j

static void	merge_sort(int *arr, int left, int right)
{
	int	v;

	if (left < right)
	{
		v = left + (right - left) / 2;
		merge_sort(arr, left, v);
		merge_sort(arr, v + 1, right);
		merge(arr, left, v, right);
	}
}

static int	binary_search(int *arr, int size, int value)
{
	int	v[3];

	v[0] = 0;
	v[1] = size - 1;
	while (v[0] <= v[1])
	{
		v[2] = v[0] + (v[1] - v[0]) / 2;
		if (arr[v[2]] == value)
			return (v[2]);
		if (arr[v[2]] < value)
			v[0] = v[2] + 1;
		else
			v[1] = v[2] - 1;
	}
	return (0);
}
// v[0]=left, v[1]=right, v[2]=mid

void	index_stack(t_stack *a)
{
	int		v[2];
	int		*arr;
	t_stack	*curr;

	if (!a)
		return ;
	v[0] = stack_len(a);
	arr = malloc(sizeof(int) * v[0]);
	if (!arr)
		return ;
	curr = a;
	v[1] = 0;
	while (curr)
	{
		arr[v[1]++] = curr->value;
		curr = curr->next;
	}
	merge_sort(arr, 0, v[0] - 1);
	curr = a;
	while (curr)
	{
		curr->index = binary_search(arr, v[0], curr->value);
		curr = curr->next;
	}
	free(arr);
}
// v[0]=size, v[1]=i