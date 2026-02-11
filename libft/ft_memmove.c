/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:50:04 by mledda            #+#    #+#             */
/*   Updated: 2025/11/11 18:58:47 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	i = 0;
	src1 = (const unsigned char *)src;
	dest1 = (unsigned char *)dest;
	if (dest < src)
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (n != 0)
		{
			dest1[n - 1] = src1[n - 1];
			n--;
		}
	}
	return (dest);
}
