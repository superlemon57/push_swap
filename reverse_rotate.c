/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:24 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/19 15:47:21 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(StackElement **s)
{
	StackElement	*prev;
	StackElement	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(StackElement **a, t_count_operations *bench)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	bench->count_rra += 1;
}

void	rrb(StackElement **b, t_count_operations *bench)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	bench->count_rrb += 1;
}

void	rrr(StackElement **a, StackElement **b, t_count_operations *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	bench->count_rrr += 1;
}
