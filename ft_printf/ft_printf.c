/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmigue <andmigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:49:48 by andmigue          #+#    #+#             */
/*   Updated: 2026/06/15 18:30:38 by andmigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier(char str, va_list args)
{
	char	*low;
	char	*up;

	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	if (str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str == 'u')
		return (ft_putnbr_un(va_arg(args, unsigned int)));
	else if (str == 'x')
		return (ft_printhex(va_arg(args, unsigned int), low));
	else if (str == 'X')
		return (ft_printhex(va_arg(args, unsigned int), up));
	else if (str == 'p')
		return (ft_printptr(va_arg(args, unsigned long)));
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += ft_specifier(*(++s), args);
			if (*s == '\0')
				return (va_end(args), -1);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	return (va_end(args), count);
}

/* #include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("char:     [%%%% c%%%s ]\n", "A");
	ft_printf("string:   [%s]\n", "hello");
	ft_printf("NULL str: [%s]\n", (char *)NULL);
	ft_printf("int:      [%d]\n", 42);
	ft_printf("negative: [%d]\n", -42);
	ft_printf("INT_MAX:  [%d]\n", INT_MAX);
	ft_printf("INT_MIN:  [%d]\n", INT_MIN);
	ft_printf("unsigned: [%u]\n", UINT_MAX);
	ft_printf("hex low:  [%x]\n", 255);
 	ft_printf("hex up:   [%X]\n", 255);
 	ft_printf("pointer:  [%p]\n", (void *)0xdeadbeef);
 	ft_printf("NULL ptr: [%p]\n", (void *)0);
	ft_printf("percent:  [%%]\n");
 	return (0);
} */
