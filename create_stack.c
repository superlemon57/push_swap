/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:18 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 16:54:58 by mledda           ###   ########.fr       */
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

int	stack_size(StackElement *s)
{
	int	count;

	count = 0;
	while (s)
	{
		count++;
		s = s->next;
	}
	return (count);
}

void	print_stack(Stack st)
{
	while (!is_empty_stack(st))
	{
		ft_printf_fd(2, "%d\n", st->value);
		st = st->next;
	}
}

StackElement	*new_node(int value)
{
	StackElement	*new;

	new = malloc(sizeof(StackElement));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
