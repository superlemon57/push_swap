/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:50 by mledda            #+#    #+#             */
/*   Updated: 2026/02/16 19:50:43 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack_index(StackElement *st)
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
int	main(int argc, char **argv)
{
	char			*s;
	StackElement	*a;

	s = "NULL";
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
	//ft_printf("%s\n", s);
	a = stack_a(s);
	//print_stack(a);
	//indexation(&a);
	//print_stack_index(a);
	bucket_sort(&a);
	// sa(&a);
	print_stack(a);
	free(s);
	free_stack(a);
	return (0);
}
