/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:12 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/11 17:29:12 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_count_operations
{
        int     count_pa;
        int     count_pb;
        int     count_sa;
        int     count_sb;
        int     count_ss;
        int     count_ra;
        int     count_rb;
        int     count_rr;
        int     count_rra;
        int     count_rrb;
        int     count_rrr;
} t_count_operations;

int stack_size(StackElement *s)
{
    int count = 0;

    while (s)
    {
        count++;
        s = s->next;
    }
    return (count);
}

int is_sorted(StackElement *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

int find_min(StackElement *a)
{
    int min;

    min = a->value;
    while (a)
    {
        if (a->value < min)
            min = a->value;
        a = a->next;
    }
    return (min);
}

int find_pos(StackElement *a, int value)
{
    int i = 0;

    while (a)
    {
        if (a->value == value)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

void bring_to_top(StackElement **a, int pos)
{
    int size;

    size = stack_size(*a);

    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        while (pos++ < size)
            rra(a);
    }
}


void sort_three(StackElement **a)
{
    int x;
    int y;
    int z;

    x = (*a)->value;
    y = (*a)->next->value;
    z = (*a)->next->next->value;

    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        rra(a);
}


void simple_sort(StackElement **a, StackElement **b)
{
    int min;
    int pos;

    if (is_sorted(*a))
        return ;
    while (stack_size(*a) > 3)
    {
        min = find_min(*a);
        pos = find_pos(*a, min);

        bring_to_top(a, pos);
        pb(a, b);
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}