/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:45:54 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 14:11:15 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_which_index(char c, va_list ap);
int		ft_putstrcount(const char *s);
int		ft_putnbrcount(int n);
int		ft_putcharcount(char c);
int		ft_puthexacount(unsigned long n);
int		ft_putuphexacount(unsigned int n);
int		ft_putnbru(unsigned int n);
int		ft_adressp(void const *p);

#endif