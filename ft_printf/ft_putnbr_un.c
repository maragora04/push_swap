/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:23:22 by andmigue          #+#    #+#             */
/*   Updated: 2026/07/17 15:32:40 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned long n, int fd)
{
	unsigned char	c;
	int				count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_un(n / 10, fd);
	c = (n % 10) + '0';
	count += ft_putchar_fd(c, fd);
	return (count);
}
