/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:00:12 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:27:40 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"
#include <stdio.h> 

int	ft_which_index(int fd, char c, va_list ap)
{
	if (c == 'c')
		return (ft_putcharcount_fd(fd, va_arg(ap, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbrcount_fd(fd, va_arg(ap, int)));
	if (c == 's')
		return (ft_putstrcount_fd(fd, va_arg(ap, char *)));
	if (c == 'p')
		return (ft_adress_fd(fd, va_arg(ap, void *)));
	if (c == 'u')
		return (ft_putnbru_fd(fd, va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthexacount_fd(fd, va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_putuphexacount_fd(fd, va_arg(ap, unsigned int)));
	if (c == '%')
		return (ft_putcharcount_fd(fd, '%'));
	return (0);
}
