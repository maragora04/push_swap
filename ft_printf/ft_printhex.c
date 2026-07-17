/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:33:36 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 15:33:34 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, char *base, int fd)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_printhex(n / 16, base, fd);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}
