/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:28 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/19 15:42:50 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(StackElement **s)
{
	StackElement	*first;
	StackElement	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(StackElement **a, t_count_operations *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	bench->count_ra += 1;
}

void	rb(StackElement **b, t_count_operations *bench)
{
	rotate(b);
	write(1, "rb\n", 3);
	bench->count_rb += 1;
}

void	rr(StackElement **a, StackElement **b, t_count_operations *bench)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	bench->count_rr += 1;
}
