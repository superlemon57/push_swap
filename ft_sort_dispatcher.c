/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:28:38 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/28 03:53:09 by tlopez           ###   ########.fr       */
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

static const char	*get_strategy_label(float disorder, t_count_flag flags)
{
	if (flags.simple)
		return ("Simple sort / O(n²)");
	if (flags.medium)
		return ("Bucket sort / O(n√n)");
	if (flags.complex)
		return ("Radix sort / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive -> Simple sort / O(n²)");
	if (disorder < 0.5)
		return ("Adaptive -> Bucket sort / O(n√n)");
	return ("Adaptive -> Radix sort / O(n log n)");
}

static void	print_bench(t_count_operations *ops, float disorder,
		t_count_flag flags)
{
	int	total;

	total = ops->count_pa + ops->count_pb + ops->count_sa + ops->count_sb
		+ ops->count_ss + ops->count_ra + ops->count_rb + ops->count_rr
		+ ops->count_rra + ops->count_rrb + ops->count_rrr;
	ft_printf_fd(2, "[bench] disorder:   %f%%\n", disorder * 100);
	ft_printf_fd(2, "[bench] strategy:   %s\n",
		get_strategy_label(disorder, flags));
	ft_printf_fd(2, "[bench] total_ops:  %d\n", total);
	ft_printf_fd(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		ops->count_sa, ops->count_sb, ops->count_ss,
		ops->count_pa, ops->count_pb);
	ft_printf_fd(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		ops->count_ra, ops->count_rb, ops->count_rr,
		ops->count_rra, ops->count_rrb, ops->count_rrr);
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
	else
	{
		if (disorder < 0.2)
			simple_sort(a, ops);
		else if (disorder < 0.5)
			bucket_sort(a, ops);
		else
			radix_sort(a, ops);
	}
	if (flags.bench)
		print_bench(ops, disorder, flags);
}

void	choose_sort(StackElement **a, t_count_operations *ops,
		t_count_flag flags)
{
	execute_sort(a, ops, flags);
}