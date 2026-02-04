/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:19:32 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 17:18:19 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static size_t	count_world(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*copy_world_of_index(char const *s, char c, size_t index)
{
	size_t	count;
	size_t	i;
		size_t	start;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		if (s[i] && index == count)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			return (ft_substr(s, start, (i - start)));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arrays;
	size_t	count;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	count = count_world(s, c);
	arrays = (char **)ft_calloc(sizeof (char *), (count + 1));
	if (!arrays)
		return (NULL);
	arrays[count] = 0;
	while ((j + 1) <= count)
	{
		arrays[j] = copy_world_of_index (s, c, (j + 1));
		if (arrays[j] == NULL)
			return (NULL);
		j++;
	}
	return (arrays);
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
	size_t			i;
	StackElement	*firstnode;
	StackElement	*new;
	StackElement	*current;
	char			**arrays;

	arrays = ft_split(s, ' ');
	if (!arrays || !arrays[0])
		return (NULL);
	firstnode = malloc(sizeof(StackElement));
	if (!firstnode)
		return (NULL);
	firstnode->value = ft_atoi(arrays[0]);
	firstnode->next = NULL;
	current = firstnode;
	i = 1;
	while (arrays[i])
	{
		new = malloc(sizeof(StackElement));
		if (!new)
			return (NULL);
		new->value = ft_atoi(arrays[i]);
		new->next = NULL;
		current->next = new;
		current = new;
		i++;
	}
	return (free_split(arrays), firstnode);
}
