/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:12:40 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 15:31:34 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf_fd( int fd, const char *s, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr(long n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_un(unsigned long n, int fd);
int		ft_printhex(unsigned long n, char *base, int fd);
int		ft_printptr(unsigned long n, int fd);

#endif