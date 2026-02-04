/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:25:05 by mledda            #+#    #+#             */
/*   Updated: 2025/11/16 11:49:19 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
