/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:26:24 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:26:30 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putnbru_fd(int fd, unsigned int n)
{
	int				i;
	unsigned long	nb;

	nb = n;
	i = 0;
	if (nb <= 9)
		i += ft_putcharcount_fd(fd, nb + 48);
	else
	{
		i += ft_putnbru_fd(fd, nb / 10);
		i += ft_putnbru_fd(fd, nb % 10);
	}
	return (i);
}
