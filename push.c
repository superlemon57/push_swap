/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:21 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/19 15:49:17 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(StackElement **src, StackElement **dest)
{
	StackElement	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(StackElement **a, StackElement **b, t_count_operations *bench)
{
	push(b, a);
	write(1, "pa\n", 3);
	bench->count_pa += 1;
}

void	pb(StackElement **a, StackElement **b, t_count_operations *bench)
{
	push(a, b);
	write(1, "pb\n", 3);
	bench->count_pb += 1;
}
