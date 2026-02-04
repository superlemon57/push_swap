/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:18 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 17:18:19 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	new_stack(void)
{
	return (NULL);
}

Bool	is_empty_stack(Stack st)
{
	if (st == NULL)
		return (true);
	return (false);
}


void	print_stack(Stack st)
{
	if (is_empty_stack(st))
	{
		printf ("rien à afficher.\n");
		return ;
	}
	while (!is_empty_stack(st))
	{
		printf("%d\n", st->value);
		st = st->next;
	}
}
