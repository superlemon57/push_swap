/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:58:15 by mledda            #+#    #+#             */
/*   Updated: 2025/11/11 11:39:02 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
		write(1,"Entrez une lettre: ", 19);
		l = getchar();
		if (ft_isalpha(l))
			write(1, "\nIs alpha\n", 10);
		else
			write(1, "\nNot alpha\n", 11);
		getchar();
	}
}*/
