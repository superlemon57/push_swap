/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:30 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/22 15:18:36 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(StackElement **s)
{
    StackElement    *first;
    StackElement    *second;

    if (!s || !*s || !(*s)->next)
        return ;
    first = *s;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *s = second;
}

void    sa(StackElement **a, t_count_operations *ops)
{
    swap(a);
    ops->count_sa++;
    write(1, "sa\n", 3);
}

void    sb(StackElement **b, t_count_operations *ops)
{
    swap(b);
    ops->count_sb++;
    write(1, "sb\n", 3);
}

void    ss(StackElement **a, StackElement **b, t_count_operations *ops)
{
    swap(a);
    swap(b);
    ops->count_ss++;
    write(1, "ss\n", 3);
}