/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:43 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 14:32:05 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*s1;
	size_t		i;

	i = 0;
	s1 = (char *) malloc ((ft_strlen(s) + 1));
	if (!s1)
		return (NULL);
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	s3 = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 3) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	s3[j++] = ' ';
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j++] = ' ';
	s3[j] = '\0';
	return (s3);
}

char	*add_argv(int argc, char **argv)
{
	int		i;
	char	*s_total;
	char	*temp;

	s_total = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (!isbench(argv[i]) && !issimple(argv[i]) && !ismedium(argv[i])
			&& !iscomplex(argv[i]) && !isadaptive(argv[i]))
		{
			temp = s_total;
			s_total = ft_strjoin_space(temp, argv[i]);
			free(temp);
		}
		i++;
	}
	return (s_total);
	if (s_total && s_total[0] != '\0')
		free(s_total);
}

int	check_s(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '+' || s[i] == '-'
			|| (s[i] <= '9' && s[i] >= '0') || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
