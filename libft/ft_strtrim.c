/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:53:16 by mledda            #+#    #+#             */
/*   Updated: 2025/11/19 17:27:23 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*stronc;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	k = ft_strlen(s1) - 1;
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_isset(s1[i], set) == 1)
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (k > 0 && k > i && ft_isset(s1[k], set) == 1)
		k--;
	stronc = (char *) malloc((k - i + 2) * sizeof(char));
	if (!stronc)
		return (NULL);
	while (i <= k)
		stronc[j++] = s1[i++];
	stronc[j] = '\0';
	return (stronc);
}
// int	main()
// {
// 	char	*test = "   xxx   xxx";
// 	char	*d = " x";	
// 	char *a = ft_strtrim(test, d);
// 	printf("%s", a);
// 	free(a);
// }
