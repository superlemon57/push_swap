/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:34:45 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/11 15:34:48 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(StackElement **src, StackElement **dest)
{
    StackElement *tmp;

    if (!src || !*src)
        return;

    tmp = *src;
    *src = tmp->next;

    tmp->next = *dest;
    *dest = tmp;
}

void    pa(StackElement **a, StackElement **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(StackElement **a, StackElement **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
