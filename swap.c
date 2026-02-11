/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:30 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/11 17:29:31 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(StackElement **s)
{
    StackElement *first;
    StackElement *second;

    if (!s || !*s || !(*s)->next)
        return;

    first = *s;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *s = second;
}

void    sa(StackElement **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(StackElement **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(StackElement **a, StackElement **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}