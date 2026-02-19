/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:30 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/19 15:50:58 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(StackElement **s)
{
	StackElement	*first;
	StackElement	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(StackElement **a, t_count_operations *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	bench->count_sa += 1;
}

void	sb(StackElement **b, t_count_operations *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	bench->count_sb += 1;
}

void	ss(StackElement **a, StackElement **b, t_count_operations *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	bench->count_ss += 1;
}