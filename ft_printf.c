/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:15:07 by amaula            #+#    #+#             */
/*   Updated: 2024/05/12 13:36:06 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_variable(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));/*
	if (specifier == 'd')
		return (ft_putdec(va_arg(args, int)));
	if (specifier == 'i')
		return (ft_putint(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));*/
	if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));/*
	if (specifier == 'X')
		return (ft_puthex_caps(va_arg(args, unsigned int)));*/
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		tmp;
	int		ret;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				tmp = write(1, "%", 1);
			else
				tmp = print_variable(args, *format);
			if (tmp < 0)
				return (-1);
			ret += tmp;
		}
		else
		{
			tmp += write(1, format, 1);
			if (tmp < 0)
				return (-1);
			ret += tmp;
		}
		format++;
	}
	va_end(args);
	return (ret);
}

#include <stdio.h>

int main(void)
{
	char c = 'c';
	char *s = "kissa";
	int i = 100;
	printf("Printing just a string:\n");
	printf("asd\n");
	ft_printf("asd\n");

	printf("\nPrinting a char:\n");
	printf("%c\n", c);
	ft_printf("%c\n", c);

	printf("\nPrinting a string:\n");
	printf("%s\n", s);
	ft_printf("%s\n", s);

	printf("\nPrinting a pointer:\n");
	printf("%p\n", &c);
	ft_printf("%p\n", &c);

	printf("\nPrinting %i in hexadecimal:\n", i);
	printf("%x\n", i);
	ft_printf("%x\n", i);
	return 0;
}
