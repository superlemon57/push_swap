/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexacount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:33:56 by mledda            #+#    #+#             */
/*   Updated: 2025/12/07 16:21:11 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexacount(unsigned long n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
		i += ft_putcharcount(base[n]);
	else
	{
		i += ft_puthexacount(n / 16);
		i += ft_puthexacount(n % 16);
	}
	return (i);
}
