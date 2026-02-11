/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:01:47 by mledda            #+#    #+#             */
/*   Updated: 2025/11/16 13:46:30 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			total;

	total = nmemb * size;
	i = 0;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	p = malloc (total);
	if (p == NULL)
		return (NULL);
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (p);
	free(p);
}
