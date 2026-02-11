/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:41:52 by mledda            #+#    #+#             */
/*   Updated: 2025/11/26 11:47:30 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
