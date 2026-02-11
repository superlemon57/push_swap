/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:19:32 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 14:09:05 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(StackElement *lst)
{
	StackElement	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	no_duplicate(StackElement *a)
{
	StackElement	*current;
	StackElement	*runner;

	current = a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
			{
				write (1, "duplicate\n", 10);
				return (0);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

void	free_split(char **arrays)
{
	size_t	i;

	i = 0;
	if (!arrays)
		return ;
	while (arrays[i])
	{
		free(arrays[i]);
		i++;
	}
	free(arrays);
}

StackElement	*stack_a(char *s)
{
	StackElement	*first;
	StackElement	*cur;
	char			**arr;
	int				i;

	arr = ft_split(s, ' ');
	if (!arr || !arr[0])
		return (NULL);
	first = new_node(ft_atoi_mod(arr[0]));
	if (!first)
		return (free_split(arr), NULL);
	cur = first;
	i = 0;
	while (arr[++i])
	{
		cur->next = new_node(ft_atoi_mod(arr[i]));
		if (!cur->next)
			return (free_split(arr), free_stack(first), NULL);
		cur = cur->next;
	}
	free_split(arr);
	if (!no_duplicate(first))
		return (free_stack(first), NULL);
	return (first);
}
