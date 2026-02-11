/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adressp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:43:09 by mledda            #+#    #+#             */
/*   Updated: 2025/12/07 16:40:34 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adressp(void const *p)
{
	int	i;

	i = 0;
	if (!p)
		i += ft_putstrcount("(nil)");
	else
	{
		i += ft_putstrcount("0x");
		i += ft_puthexacount((unsigned long)p);
	}
	return (i);
}
