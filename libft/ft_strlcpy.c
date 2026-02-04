/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:29:14 by mledda            #+#    #+#             */
/*   Updated: 2025/11/11 18:57:07 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!(src))
		return (0);
	if (!dst || (size < 1))
		return (ft_strlen(src));
	if (ft_strlen(src) <= (size - 1))
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
