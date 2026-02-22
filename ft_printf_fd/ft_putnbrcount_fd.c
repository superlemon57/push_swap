/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcount_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:58:33 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:25:57 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putnbrcount_fd(int fd, int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += ft_putcharcount_fd(fd, '-');
		nb = -nb;
	}
	if (nb < 10)
		i += ft_putcharcount_fd(fd, nb + 48);
	else
	{
		i += ft_putnbrcount_fd(fd, nb / 10);
		i += ft_putnbrcount_fd(fd, nb % 10);
	}
	return (i);
}
