/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:50 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 13:23:05 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("%s\n", s);
	a = stack_a(s);
	print_stack(a);
	// sa(&a);
	// print_stack(a);
	free(s);
	free_stack(a);
	return (0);
}
