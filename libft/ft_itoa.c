/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:17:28 by mledda            #+#    #+#             */
/*   Updated: 2025/11/26 11:28:58 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	len_number(long n)
{
	long int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = (n / 10);
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	i;
	char	*result;
	int		len;

	nb = n;
	len = len_number(nb);
	i = len - 1;
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
		nb = (-1 * nb);
	while (nb != 0)
	{
		result[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

// int main(void)
// {
//     printf("%s\n", ft_itoa(0));
//     printf("%s\n", ft_itoa(32767));
//     printf("%s\n", ft_itoa(-32768));
//     printf("%s\n", ft_itoa(-98));
// }