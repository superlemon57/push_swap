/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:02:12 by mledda            #+#    #+#             */
/*   Updated: 2025/12/07 16:39:31 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	int				i;
	unsigned long	nb;

	nb = n;
	i = 0;
	if (n <= 9)
		i += ft_putcharcount(n + 48);
	else
	{
		i += ft_putnbru(n / 10);
		i += ft_putnbru(n % 10);
	}
	return (i);
}
