/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:28 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/11 17:29:29 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(StackElement **s)
{
    StackElement *first;
    StackElement *last;

    if (!s || !*s || !(*s)->next)
        return;

    first = *s;
    *s = first->next;

    last = *s;
    while (last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void    ra(StackElement **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(StackElement **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(StackElement **a, StackElement **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
