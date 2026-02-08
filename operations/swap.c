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