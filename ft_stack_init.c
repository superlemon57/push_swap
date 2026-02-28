/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:19:32 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 17:34:48 by tlopez           ###   ########.fr       */
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
				ft_printf_fd(2, "Error\n");
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
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

static StackElement	*build_stack(char **arr)
{
	StackElement	*first;
	StackElement	*cur;
	int				i;
	int				value;

	value = ft_atoi_mod(arr[0]);
	first = new_node(value);
	if (!first)
		return (NULL);
	cur = first;
	i = 0;
	while (arr[++i])
	{
		value = ft_atoi_mod(arr[i]);
		cur->next = new_node(value);
		if (!cur->next)
			return (free_stack(first), NULL);
		cur = cur->next;
	}
	return (first);
}

StackElement	*stack_a(char *s)
{
	StackElement	*stack;
	char			**arr;

	arr = ft_split(s, ' ');
	if (!arr || !arr[0])
		return (NULL);
	stack = build_stack(arr);
	if (!stack)
	{
		return(free_stack(stack), NULL);
	}
	free_split(arr);
	if (!stack || no_duplicate(stack) == 1)
	{	
		return (free_stack(stack), NULL);
	}
	return (stack);
}
