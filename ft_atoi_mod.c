/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:50:49 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 16:08:42 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_mod( char *str)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		return (write(2, "error_sign\n", 11), 0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		return (write(2, "error\n", 6), 0);
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

