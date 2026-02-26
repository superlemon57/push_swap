/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:50 by mledda            #+#    #+#             */
/*   Updated: 2026/02/26 15:59:28 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_operations(t_count_operations *ops)
{
	ops->count_pa = 0;
	ops->count_pb = 0;
	ops->count_sa = 0;
	ops->count_sb = 0;
	ops->count_ss = 0;
	ops->count_ra = 0;
	ops->count_rb = 0;
	ops->count_rr = 0;
	ops->count_rra = 0;
	ops->count_rrb = 0;
	ops->count_rrr = 0;
}

void	print_operations(t_count_operations *ops)
{
	int	total;

	total = ops->count_pa + ops->count_pb + ops->count_sa + ops->count_sb
		+ ops->count_ss + ops->count_ra + ops->count_rb + ops->count_rr
		+ ops->count_rra + ops->count_rrb + ops->count_rrr;
	ft_printf_fd(2, "--- Operations ---\n");
	ft_printf_fd(2, "pa: %d | pb: %d\n", ops->count_pa, ops->count_pb);
	ft_printf_fd(2, "sa: %d | sb: %d | ss: %d\n", ops->count_sa, ops->count_sb, ops->count_ss);
	ft_printf_fd(2, "ra: %d | rb: %d | rr: %d\n", ops->count_ra, ops->count_rb, ops->count_rr);
	ft_printf_fd(2, "rra: %d | rrb: %d | rrr: %d\n", ops->count_rra, ops->count_rrb, ops->count_rrr);
	ft_printf_fd(2, "Total: %d\n", total);
}

void    print_stack_index(StackElement *st)
{
	if (!st)
	{
		ft_printf_fd(2, "Stack is empty\n");
		return ;
	}
	while (st)
	{
		ft_printf_fd(1, "Value: %d | Index: %d\n", st->value, st->index);
		st = st->next;
	}
}

int	main(int argc, char **argv)
{
	char				*s;
	StackElement		*a;
	//StackElement		*b;
	t_count_operations	ops;

	s = "NULL";
	//b = NULL;
	init_operations(&ops);
	if (check_flags(ft_count_flags(argc, argv)) == 0)
		return (0);
	s = add_argv(argc, argv);
	if (!s)
		return (0);
	if (check_s(s) == 0)
	{
		ft_printf_fd(2, "ERROR\n");
		return (free(s), 0);
	}
	//ft_printf("%s\n", s);
	a = stack_a(s);
	//print_stack(a);
	indexation(&a);
	printf("%f\n",compute_disorder_indexed(a));
	//print_stack_index(a);
	//bucket_sort(&a, &ops);
	simple_sort(&a, &ops);
	//radix_sort(&a, &b, &ops);
	// sa(&a);
	print_stack(a);
	print_operations(&ops);
	free(s);
	free_stack(a);
	return (0);
}