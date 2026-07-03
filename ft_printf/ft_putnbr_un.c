/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:23:22 by andmigue          #+#    #+#             */
/*   Updated: 2026/05/20 17:23:29 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned long n)
{
	unsigned char	c;
	int				count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_un(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}
