/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:04:59 by mledda            #+#    #+#             */
/*   Updated: 2025/11/19 18:14:17 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big)
		return (NULL);
	if (!little || little[0] == '\0')
		return ((char *)big);
	while ((big[j] != '\0') && (j < len))
	{
		while (big[j + i] == little[i] && (i + j) < len)
		{
			i++;
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
		j++;
		i = 0;
	}
	return (NULL);
}
