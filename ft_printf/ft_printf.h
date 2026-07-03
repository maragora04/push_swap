/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:12:40 by andmigue          #+#    #+#             */
/*   Updated: 2026/05/24 11:48:29 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(long n);
int		ft_putstr(char *s);
int		ft_putnbr_un(unsigned long n);
int		ft_printhex(unsigned long n, char *base);
int		ft_printptr(unsigned long n);

#endif