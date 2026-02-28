/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:50:49 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 17:34:22 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_mod(char *str)
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
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
		{
			ft_printf_fd(2, "Error\n");
			exit(1);
			//return (write(2, "Error\n", 6), 1);
		}
	}
	// if (!(str[i] >= '0' && str[i] <= '9'))
	// 	return (write(2, "Error\n", 6), 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
		//return (write(2, "Error\n", 6), 1);
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
		//return (write(2, "Error\n", 6), 1);
	}
	return ((int)(sign * result));
}