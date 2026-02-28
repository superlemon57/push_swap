/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:50:49 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 03:51:32 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error_and_exit(void)
{
	write(2, "error\n", 6);
	exit(1);
}

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
		if (str[i++] == '-')
			sign = -1;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		print_error_and_exit();
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		print_error_and_exit();
	return ((int)(sign * result));
}