/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:00:12 by mledda            #+#    #+#             */
/*   Updated: 2025/12/07 16:38:48 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

int	ft_which_index(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putcharcount(va_arg(ap, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbrcount(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstrcount(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_adressp(va_arg(ap, void *)));
	if (c == 'u')
		return (ft_putnbru(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthexacount (va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_putuphexacount (va_arg(ap, unsigned int)));
	if (c == '%')
		return (ft_putcharcount('%'));
	return (0);
}
