/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:18 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 12:04:33 by mledda           ###   ########.fr       */
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

Stack	push_stack(Stack st, int x)
{
	StackElement	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (0);
	element->value = x;
	element->next = st;
	return (element);
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
