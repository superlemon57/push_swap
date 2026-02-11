/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:58:33 by mledda            #+#    #+#             */
/*   Updated: 2025/12/07 15:17:45 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrcount(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += ft_putcharcount('-');
		nb = -nb;
	}
	if (nb < 10)
		i += ft_putcharcount(nb + 48);
	else
	{
		i += ft_putnbrcount(nb / 10);
		i += ft_putnbrcount(nb % 10);
	}
	return (i);
}
