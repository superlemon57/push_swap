/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:12 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/22 15:57:44 by tlopez           ###   ########.fr       */
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

void	bring_to_top(StackElement **a, int pos, t_count_operations *ops)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, ops);
	}
	else
	{
		while (pos++ < size)
			rra(a, ops);
	}
}

void	sort_three(StackElement **a, t_count_operations *ops)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, ops);
	else if (x > y && y > z)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (x > y && y < z && x > z)
		ra(a, ops);
	else if (x < y && y > z && x < z)
	{
		sa(a, ops);
		ra(a, ops);
	}
	else if (x < y && y > z && x > z)
		rra(a, ops);
}

void	simple_sort(StackElement **a, t_count_operations *ops)
{
    int				min;
    int				pos;
    StackElement	*b;

    b = NULL;
    if (is_sorted(*a))
        return ;
    while (stack_size(*a) > 3)
    {
        min = find_min(*a);
        pos = find_pos(*a, min);
        bring_to_top(a, pos, ops);
        pb(a, &b, ops);
    }
    sort_three(a, ops);
    while (b)
        pa(a, &b, ops);
}