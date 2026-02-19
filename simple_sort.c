/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:12 by tlopez            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/19 16:47:25 by mledda           ###   ########.fr       */
=======
/*   Updated: 2026/02/16 20:08:57 by tlopez           ###   ########.fr       */
>>>>>>> 0035c8f183ef70975ada00befb8f07e1c70c852b
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

void	bring_to_top(StackElement **a, int pos, t_count_operations *bench)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, bench);
	}
	else
	{
		while (pos++ < size)
			rra(a, bench);
	}
}

void	sort_three(StackElement **a, t_count_operations *bench)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, bench);
	else if (x > y && y > z)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (x > y && y < z && x > z)
		ra(a, bench);
	else if (x < y && y > z && x < z)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (x < y && y > z && x > z)
		rra(a, bench);
}

void	simple_sort(StackElement **a,
		t_count_operations *bench)
{
	int				min;
	int				pos;
	StackElement	**b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
	{
		min = find_min(*a);
		pos = find_pos(*a, min);
		bring_to_top(a, pos, bench);
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
