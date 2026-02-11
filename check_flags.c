/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:29 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 14:36:38 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count_flag	ft_count_flags(int argc, char **argv)
{
	int				i;
	t_count_flag	j;

	i = 1;
	j.complex = 0;
	j.simple = 0;
	j.medium = 0;
	j.bench = 0;
	j.adaptive = 0;
	while (i < argc)
	{
		if (isbench(argv[i]))
			j.bench += 1;
		if (issimple(argv[i]))
			j.simple += 1;
		if (ismedium(argv[i]))
			j.medium += 1;
		if (iscomplex(argv[i]))
			j.complex += 1;
		if (isadaptive(argv[i]))
			j.adaptive += 1;
		i++;
	}
	return (j);
}

int	check_flags(t_count_flag j)
{
	if (j.simple > 0 && (j.medium > 0 || j.complex > 0 || j.adaptive > 0))
	{
		printf ("erreur\n");
		return (0);
	}
	if (j.medium > 0 && (j.complex > 0 || j.adaptive > 0))
	{
		printf ("erreur\n");
		return (0);
	}
	if (j.complex > 0 && j.adaptive > 0)
	{
		printf ("erreur\n");
		return (0);
	}
	else
		return (1);
}
