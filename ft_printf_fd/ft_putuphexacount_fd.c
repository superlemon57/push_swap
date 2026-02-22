/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphexacount_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:27:17 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:27:26 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putuphexacount_fd(int fd, unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	if (n < 16)
		i += ft_putcharcount_fd(fd, base[n]);
	else
	{
		i += ft_putuphexacount_fd(fd, (n / 16));
		i += ft_putuphexacount_fd(fd, (n % 16));
	}
	return (i);
}
