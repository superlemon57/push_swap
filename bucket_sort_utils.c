/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:49:59 by mledda            #+#    #+#             */
/*   Updated: 2026/02/16 20:05:58 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaparr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swaparr(&arr[i], &arr[j]);
		}
		j++;
	}
	swaparr(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int arr[], int low, int high)
{
	int	pi;

	pi = 0;
	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi -1);
		quick_sort(arr, pi + 1, high);
	}
}

static void	fill_index(StackElement *a, int *arr, int n)
{
	StackElement	*curr;
	int				i;

	curr = a;
	while (curr)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == curr->value)
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

int	indexation(StackElement **a)
{
	int				*arr;
	int				n;
	StackElement	*curr;
	int				i;

	n = stack_size(*a);
	curr = *a;
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (1);
	i = 0;
	while (curr)
	{
		arr[i] = curr->value;
		i++;
		curr = curr->next;
	}
	quick_sort(arr, 0, n - 1);
	curr = *a;
	fill_index(*a, arr, n);
	free(arr);
	return (0);
}

