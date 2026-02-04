/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:48:04 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 12:09:36 by mledda           ###   ########.fr       */
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
