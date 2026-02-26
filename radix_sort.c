/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:07:27 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/26 15:01:44 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(StackElement *stack)
{
	int	max_index;
	int	max_bits;

	max_index = 0;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(StackElement **a, t_count_operations *ops)
{
	int				i;
	int				j;
	int				size;
	int				max_bits;
	StackElement	*current;
	StackElement	*b;

	b = NULL;
	i = 0;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current = *a;
			if (((current->index >> i) & 1) == 1)
				ra(a, ops);
			else
				pb(a, &b, ops);
			j++;
		}
		while (b)
			pa(a, &b, ops);
		i++;
	}
}