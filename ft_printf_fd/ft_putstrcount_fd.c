/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcount_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:26:54 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 15:26:57 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

int	ft_putstrcount_fd(int fd, const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar_fd(fd, s[i]);
		i++;
	}
	return (i);
}
