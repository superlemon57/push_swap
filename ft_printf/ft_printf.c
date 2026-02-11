/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:54:59 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 14:13:24 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start (ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_which_index(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
	va_end(ap);
}

/*
int	main ()
{
	char	*s = "la plus belle ";
	int	i = 25;
	
	printf("%s\n, %d\n", s, i);
	ft_printf("%s\n, %d\n", s, i);
	return (0);
	
}
*/
