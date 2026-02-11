/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:10:06 by mledda            #+#    #+#             */
/*   Updated: 2025/11/11 11:37:13 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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
		write(1,"Entrez un caractere: ", 21);
		l = getchar();
		if (ft_isalnum(l))
			write(1, "\nIs alnum\n", 10);
		else
			write(1, "\nNot alnum\n", 11);
		getchar();
	}
}*/
