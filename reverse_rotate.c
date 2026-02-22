/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:24 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/22 15:20:47 by tlopez           ###   ########.fr       */
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

void	rra(StackElement **a, t_count_operations *ops)
{
	reverse_rotate(a);
	ops->count_rra++;
	write(1, "rra\n", 4);
}

void	rrb(StackElement **b, t_count_operations *ops)
{
	reverse_rotate(b);
	ops->count_rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(StackElement **a, StackElement **b, t_count_operations *ops)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ops->count_rrr++;
	write(1, "rrr\n", 4);
}