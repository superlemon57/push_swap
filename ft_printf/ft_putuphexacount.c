/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphexacount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:52:26 by mledda            #+#    #+#             */
/*   Updated: 2025/12/07 15:18:18 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphexacount(unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	if (n < 16)
		i += ft_putcharcount(base[n]);
	else
	{
		i += ft_putuphexacount(n / 16);
		i += ft_putuphexacount(n % 16);
	}
	return (i);
}
