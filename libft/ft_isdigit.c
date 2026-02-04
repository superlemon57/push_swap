/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:57:19 by mledda            #+#    #+#             */
/*   Updated: 2025/11/09 18:19:06 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int l = 1;

	while(l != EOF)
	{
		write(1,"Entrez un chiffre: ", 19);
		l = getchar();
		if (ft_isdigit(l))
			write(1, "\nIs digit\n", 10);
		else
			write(1, "\nNot digit\n", 11);
		getchar();
	}
}
*/
