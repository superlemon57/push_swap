/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:24 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/15 16:36:54 by mledda           ###   ########.fr       */
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

void	rra(StackElement **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(StackElement **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(StackElement **a, StackElement **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
