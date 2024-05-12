/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:15:07 by amaula            #+#    #+#             */
/*   Updated: 2024/05/12 13:01:58 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_variable(va_list args, char conchr)
{
	if (conchr == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (conchr == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (conchr == 'p')
		return (ft_putptr(va_arg(args, void *)));/*
	if (conchr == 'd')
		return (ft_putdec(va_arg(args, int)));
	if (conchr == 'i')
		return (ft_putint(va_arg(args, int)));
	if (conchr == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));*/
	if (conchr == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));/*
	if (conchr == 'X')
		return (ft_puthex_caps(va_arg(args, unsigned int)));*/
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		ret;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ret = write(1, "%", 1);
			else
				ret = print_variable(args, *format);
			if (ret < 0)
				return (-1);
			len += ret;
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
int main(void)
{
	int i = 15;
	void *p = &i;
	ft_printf("%p\n", p);
	printf("%p\n", p);
}
