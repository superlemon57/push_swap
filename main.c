/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:50 by mledda            #+#    #+#             */
/*   Updated: 2026/02/26 14:57:30 by tlopez           ###   ########.fr       */
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
	t_count_operations	ops;
	t_count_flag		flags;

	a = NULL;
	s = NULL;
	init_operations(&ops);

	flags = ft_count_flags(argc, argv);
	if (!check_flags(flags))
		return (0);

	s = add_argv(argc, argv);
	if (!s)
		return (0);
	if (!check_s(s))
	{
		ft_printf_fd(2, "sign error\n");
		free(s);
		return (0);
	}

	a = stack_a(s);
	indexation(&a);

	choose_sort(&a, &ops, flags);

	print_stack(a);

	free(s);
	free_stack(a);
	return (0);
}