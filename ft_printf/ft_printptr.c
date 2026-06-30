/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:45:06 by andmigue          #+#    #+#             */
/*   Updated: 2026/05/24 10:56:29 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long n)
{
	char	*low;

	low = "0123456789abcdef";
	if (!n)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_printhex(n, low));
}
