/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:45:54 by mledda            #+#    #+#             */
/*   Updated: 2026/02/26 17:15:22 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf_fd(int fd, const char *format, ...);
int		ft_which_index(int fd, char c, va_list ap);
int		ft_putstrcount_fd(int fd, const char *s);
int		ft_putnbrcount_fd(int fd, int n);
int		ft_putcharcount_fd(int fd, char c);
int		ft_puthexacount_fd(int fd, unsigned long n);
int		ft_putuphexacount_fd(int fd, unsigned int n);
int		ft_putnbru_fd(int fd, unsigned int n);
int		ft_adress_fd(int fd, void const *p);
int 	ft_putfloat_fd(int fd, double n, int precision);

#endif
