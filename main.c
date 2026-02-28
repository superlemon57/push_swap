/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:50 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 17:34:30 by tlopez           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char				*s;
	StackElement		*a;
	t_count_operations	ops;
	t_count_flag		flags;

	s = NULL;
	init_operations(&ops);
	flags = ft_count_flags(argc, argv);
	if (check_flags(flags) == 0)
		return (0);
	s = add_argv(argc, argv);
	if (!s)
		return (0);
	if (check_s(s) == 0)
		return (ft_printf_fd(2, "Error\n"), free(s), 0);
	a = stack_a(s);
	free(s);
	if (!a)
		return (0);
	indexation(&a);
	choose_sort(&a, &ops, flags);
	free_stack(a);
	return (0);
}