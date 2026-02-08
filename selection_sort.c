/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:42:13 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/08 16:33:27 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(StackElement *a) // a deplacer dans autre fichier
{
	int	count;

	count = 0;
	while (s)
	{
		count++;
		s = s->next;
	}
	return (count);
}

int	find_min(StackElement *a)
{
	int	min;

	min = a->value;
	while(a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	find_pos(StackElement *a, int value)
{
	int	i;

	i = 0;
	while(a)
	{
		if (a->value == value)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	to_top(StackElement **a, int pos)
{
	int	size;

	size = stack_size(*a);

	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}


