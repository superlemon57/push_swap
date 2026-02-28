/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:28 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/28 03:13:06 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(StackElement **s)
{
    StackElement    *first;
    StackElement    *last;

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

void    ra(StackElement **a, t_count_operations *ops)
{
    rotate(a);
    ops->count_ra++;
    write(1, "ra\n", 3);
}

void    rb(StackElement **b, t_count_operations *ops)
{
    rotate(b);
    ops->count_rb++;
    write(1, "rb\n", 3);
}

void    rr(StackElement **a, StackElement **b, t_count_operations *ops)
{
    rotate(a);
    rotate(b);
    ops->count_rr++;
    write(1, "rr\n", 3);
}