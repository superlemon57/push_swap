/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_detect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:04 by mledda            #+#    #+#             */
/*   Updated: 2026/02/28 03:13:03 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isbench(char *s)
{
	int		i;
	char	*f;

	i = 0;
	f = "--bench";
	if (!s)
		return (0);
	while (s[i] == f[i] && f[i] != '\0')
		i++;
	if (s[i] == '\0' && f[i] == '\0')
		return (1);
	else
		return (0);
}

int	issimple(char *s)
{
	int		i;
	char	*f;

	i = 0;
	f = "--simple";
	if (!s)
		return (0);
	while (s[i] == f[i] && f[i] != '\0')
		i++;
	if (s[i] == '\0' && f[i] == '\0')
		return (1);
	else
		return (0);
}

int	ismedium(char *s)
{
	int		i;
	char	*f;

	i = 0;
	f = "--medium";
	if (!s)
		return (0);
	while (s[i] == f[i] && f[i] != '\0')
		i++;
	if (s[i] == '\0' && f[i] == '\0')
		return (1);
	else
		return (0);
}

int	iscomplex(char *s)
{
	int		i;
	char	*f;

	i = 0;
	f = "--complex";
	if (!s)
		return (0);
	while (s[i] == f[i] && f[i] != '\0')
		i++;
	if (s[i] == '\0' && f[i] == '\0')
		return (1);
	else
		return (0);
}

int	isadaptive(char *s)
{
	int		i;
	char	*f;

	i = 0;
	f = "--adaptive";
	if (!s)
		return (0);
	while (s[i] == f[i] && f[i] != '\0')
		i++;
	if (s[i] == '\0' && f[i] == '\0')
		return (1);
	else
		return (0);
}
