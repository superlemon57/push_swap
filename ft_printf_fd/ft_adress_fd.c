/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:20:38 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:32:43 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_adress_fd(int fd, void const *p)
{
	int	i;

	i = 0;
	if (!p)
		i += ft_putstrcount_fd(fd, "(nil)");
	else
	{
		i += ft_putstrcount_fd(fd, "0x");
		i += ft_puthexacount_fd(fd, (unsigned long)p);
	}
	return (i);
}
