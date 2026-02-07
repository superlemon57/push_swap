// échange les 2 premiers
void    swap(t_stack **s)
{
    t_stack *first;
    t_stack *second;

    if (!s || !*s || !(*s)->next)
        return (0);

    first = *s;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *s = second;
}

void    sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void    push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;

    if (!src || !*src)
        return ;

    tmp = *src;
    *src = tmp->next;

    tmp->next = *dest;
    *dest = tmp;
}


// premier de src --> dest
void    push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;

    if (!src || !*src)
        return (0);

    tmp = *src;
    *src = tmp->next;

    tmp->next = *dest;
    *dest = tmp;
}

void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}


// premier --> dernier
void    rotate(t_stack **s)
{
    t_stack *first;
    t_stack *last;

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

void    ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}


// dernier --> premier
void    reverse_rotate(t_stack **s)
{
    t_stack *prev;
    t_stack *last;

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

void    rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}






// test
void    print_stack(t_stack *s, char name)
{
    printf("Stack %c: ", name);
    while (s)
    {
        printf("%d ", s->value);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    print_stack(a, 'A');
    sa(&a);
    print_stack(a, 'A');
}