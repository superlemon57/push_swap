/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:20:56 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 03:33:25 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	if (!format)
	{
		va_end(ap);
		return (0);
	}
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_which_index(fd, format[i], ap);
		}
		else
			count += write(fd, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}