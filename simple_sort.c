/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:12 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/15 16:34:18 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(StackElement *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	bring_to_top(StackElement **a, int pos)
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

void	sort_three(StackElement **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;

	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	simple_sort(StackElement **a, StackElement **b)
{
	int	min;
	int	pos;

	if (is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
	{
		min = find_min(*a);
		pos = find_pos(*a, min);

		bring_to_top(a, pos);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
