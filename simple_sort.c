#include <stdlib.h>
#include <unistd.h>


typedef struct StackElement
{
    int                     value;
    struct StackElement     *next;
}   StackElement;


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


// operations

void swap(StackElement **s)
{
    StackElement *first;
    StackElement *second;

    if (!s || !*s || !(*s)->next)
        return ;

    first = *s;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *s = second;
}

void sa(StackElement **a)
{
    swap(a);
    write(1, "sa\n", 3);
}


void push(StackElement **src, StackElement **dest)
{
    StackElement *tmp;

    if (!src || !*src)
        return ;

    tmp = *src;
    *src = tmp->next;

    tmp->next = *dest;
    *dest = tmp;
}

void pa(StackElement **a, StackElement **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(StackElement **a, StackElement **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}



void rotate(StackElement **s)
{
    StackElement *first;
    StackElement *last;

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

void ra(StackElement **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}



void reverse_rotate(StackElement **s)
{
    StackElement *prev;
    StackElement *last;

    if (!s || !*s || !(*s)->next)
        return ;

    prev = NULL;
    last = *s;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = *s;
    *s = last;
}

void rra(StackElement **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}



// trier


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
