/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:50:16 by mledda            #+#    #+#             */
/*   Updated: 2025/11/26 12:28:00 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (!s)
		return (NULL);
	s1 = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!s1)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		s1[i] = (*f)(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
