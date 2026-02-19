/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:52:45 by mledda            #+#    #+#             */
/*   Updated: 2026/02/19 16:18:56 by mledda           ###   ########.fr       */
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
		t_count_operations *bench)
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
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
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

void	push_b_to_a(StackElement **b, StackElement **a,  t_count_operations *bench)
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
				rb(b, bench);
		}
		else
		{
			while ((*b)->index != max_val)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	bucket_sort(StackElement **a, t_count_operations *bench)
{
	StackElement	*b;

	b = NULL;
	indexation(a);
	transfert_a_to_b(a, &b, bench);
	push_b_to_a(&b, a, bench);
}
