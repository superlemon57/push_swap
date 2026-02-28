/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:52:45 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 03:52:49 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bucket_size(int n)
{
	if (n <= 10)
		return (5);
	else if (n <= 100)
		return (15);
	else if (n <= 500)
		return (45);
	else
		return (n / 15);
}

void	transfert_a_to_b(StackElement **a, StackElement **b,
		t_count_operations *ops)
{
	int	i;
	int	range;
	int	total_elements;

	i = 0;
	total_elements = stack_size(*a);
	range = get_bucket_size(total_elements);
	while (*a != NULL)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, ops);
			rb(b, ops);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, ops);
			i++;
		}
		else
			ra(a, ops);
	}
}

int	find_max_index(StackElement *b)
{
	int	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

void	push_b_to_a(StackElement **b, StackElement **a, t_count_operations *ops)
{
	int	max_val;
	int	pos;
	int	size;

	while (*b)
	{
		max_val = find_max_index(*b);
		pos = get_pos(*b, max_val);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_val)
				rb(b, ops);
		}
		else
		{
			while ((*b)->index != max_val)
				rrb(b, ops);
		}
		pa(a, b, ops);
	}
}

void	bucket_sort(StackElement **a, t_count_operations *ops)
{
	StackElement	*b;

	b = NULL;
	indexation(a);
	transfert_a_to_b(a, &b, ops);
	push_b_to_a(&b, a, ops);
}