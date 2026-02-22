/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:21 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/22 15:20:23 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(StackElement **src, StackElement **dest)
{
    StackElement    *tmp;

    if (!src || !*src)
        return ;
    tmp = *src;
    *src = tmp->next;
    tmp->next = *dest;
    *dest = tmp;
}

void    pa(StackElement **a, StackElement **b, t_count_operations *ops)
{
    push(b, a);
    ops->count_pa++;
    write(1, "pa\n", 3);
}

void    pb(StackElement **a, StackElement **b, t_count_operations *ops)
{
    push(a, b);
    ops->count_pb++;
    write(1, "pb\n", 3);
}