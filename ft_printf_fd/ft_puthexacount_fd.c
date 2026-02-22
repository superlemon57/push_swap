/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexacount_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:24:34 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:25:47 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_puthexacount_fd(int fd, unsigned long n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
		i += ft_putcharcount_fd(fd, base[n]);
	else
	{
		i += ft_puthexacount_fd(fd, n / 16);
		i += ft_puthexacount_fd(fd, n % 16);
	}
	return (i);
}
