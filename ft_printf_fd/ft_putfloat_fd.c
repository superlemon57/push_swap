/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:01:37 by mledda            #+#    #+#             */
/*   Updated: 2026/02/26 17:19:51 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putfloat_fd(int fd, double n, int precision)
{
	long	int_part;
	double	diff;
	int		digit;

	int_part = (long)n;
	diff = n - (double)int_part;
	ft_putnbrcount_fd(fd, int_part);
	write(fd, ".", 1);
	while (precision--)
	{
		diff *= 10;
		digit = (int)diff;
		ft_putcharcount_fd(fd, digit + '0');
		diff -= digit;
	}
	return(0);
}
