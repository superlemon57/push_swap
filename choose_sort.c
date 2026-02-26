/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:28:38 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/26 14:52:27 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_sort(StackElement **a,
				t_count_operations *ops,
				t_count_flag flags)
{
	if (flags.simple)
		simple_sort(a, ops);
	else if (flags.medium)
		bucket_sort(a, ops);
	else if (flags.complex)
		radix_sort(a, ops);
	// else if (flags.adaptive)
	// 	adaptive_sort(a, ops);
	else
		simple_sort(a, ops);
}

void	choose_sort(StackElement **a,
			t_count_operations *ops,
			t_count_flag flags)
{
	execute_sort(a, ops, flags);
	if (flags.bench)
		print_operations(ops);
}