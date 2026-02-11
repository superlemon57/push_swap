/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:50:49 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 13:25:30 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_mod( char *str)
{
	int		i;
	long	result;
	int		sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "error_sign\n", 11);
			return (0);
		}
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	return ((int)(sign * result));
}

// int	main(int argc, char **argv)
// {
// 	int	i;
	
// 	i = 1;
// 	if (argc == 1)
// 		return(0);
// 	while (i < argc)
// 	{
// 		printf("%d\n", ft_atoi_mod(argv[i]));
// 		i++;
// 	}
// 	return (0);
// }

