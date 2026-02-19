/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:50 by mledda            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/19 16:41:07 by mledda           ###   ########.fr       */
=======
/*   Updated: 2026/02/16 20:18:16 by tlopez           ###   ########.fr       */
>>>>>>> 0035c8f183ef70975ada00befb8f07e1c70c852b
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_index(StackElement *st)
{
	if (!st)
	{
		printf("Stack is empty\n");
		return ;
	}
	while (st)
	{
		printf("Value: %d | Index: %d\n", st->value, st->index);
		st = st->next;
	}
}
void	print_bench(t_count_operations *bench)
{
	ft_printf("%d\n", bench->count_pa);
}
int	main(int argc, char **argv)
{
<<<<<<< HEAD
	char				*s;
	StackElement		*a;
	t_count_operations	*bench;
	StackElement		*b;
	
	bench = 0;
	b = NULL;
=======
	char			*s;
	StackElement	*a;
	StackElement	*b;

>>>>>>> 0035c8f183ef70975ada00befb8f07e1c70c852b
	s = "NULL";
	b = NULL;
	if (check_flags(ft_count_flags(argc, argv)) == 0)
		return (0);
	s = add_argv(argc, argv);
	if (!s)
		return (0);
	if (check_s(s) == 0)
	{
		printf("erreur\n");
		return (free(s), 0);
	}
<<<<<<< HEAD
	// ft_printf("%s\n", s);
	a = stack_a(s);
	// print_stack(a);
	// indexation(&a);
	// print_stack_index(a);
	simple_sort(&a, bench);
	//print_bench(bench);
=======

	//ft_printf("%s\n", s);
	a = stack_a(s);
	//print_stack(a);
	indexation(&a);
	//print_stack_index(a);
	//bucket_sort(&a);
	radix_sort(&a, &b);
>>>>>>> 0035c8f183ef70975ada00befb8f07e1c70c852b
	// sa(&a);
	print_stack(a);
	free(s);
	free_stack(a);
	return (0);
}
