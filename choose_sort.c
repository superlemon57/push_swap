/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:28:38 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/26 17:47:42 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder_indexed(StackElement *a)
{
	long			mistakes;
	long			total;
	StackElement	*outer;
	StackElement	*inner;

	if (!a || !a->next)
		return (0.0);
	mistakes = 0;
	total = 0;
	outer = a;
	while (outer->next)
	{
		inner = outer->next;
		while (inner)
		{
			total++;
			if (outer->index > inner->index)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return ((float)mistakes / total);
}

static void	execute_sort(StackElement **a, t_count_operations *ops,
		t_count_flag flags)
{
	float	disorder;

	disorder = compute_disorder_indexed(*a);
	if (flags.simple)
		simple_sort(a, ops);
	else if (flags.medium)
		bucket_sort(a, ops);
	else if (flags.complex)
		radix_sort(a, ops);
	else // adaptive
	{
		if (disorder < 0.2)
			simple_sort(a, ops);
		else if (disorder < 0.5)
			bucket_sort(a, ops);
		else
			radix_sort(a, ops);
	}

	if (flags.bench)
	{
		ft_printf_fd(2, "Disorder: %f%%\n", disorder * 100);
		if (flags.simple)
			ft_printf_fd(2, "strategy: simple_sort\n");
		else if (flags.medium)
			ft_printf_fd(2, "strategy: bucket_sort\n");
		else if (flags.complex)
			ft_printf_fd(2, "strategy: radix_sort\n");
		else // adaptive
		{
			if (disorder < 0.2)
				ft_printf_fd(2, "strategy: simple_sort\n");
			else if (disorder < 0.5)
				ft_printf_fd(2, "strategy: bucket_sort\n");
			else
				ft_printf_fd(2, "strategy: radix_sort\n");
		}
		print_operations(ops);
	}
}

void choose_sort(StackElement * *a, t_count_operations * ops,
	t_count_flag flags)
{
	execute_sort(a, ops, flags);
}