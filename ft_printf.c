/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:15:07 by amaula            #+#    #+#             */
/*   Updated: 2024/05/11 18:45:09 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putc(char c)
{
	return (write(1, &c, 1));
}

int	print_variable(va_list args, char conchr)
{
	if (conchr == 'c')
		return ((char)ft_putc(va_arg(args, int)));/*
	if (conchr == 's')
		return (ft_puts(va_arg(args, char *)));
	if (conchr == 'p')
		return (ft_putp(va_arg(args, void *)));
	if (conchr == 'd')
		return (ft_putd(va_arg(args, int)));
	if (conchr == 'i')
		return (ft_puti(va_arg(args, int)));
	if (conchr == 'u')
		return (ft_putu(va_arg(args, unsigned int)));
	if (conchr == 'x')
		return (ft_putx(va_arg(args, unsigned int)));
	if (conchr == 'X')
		return (ft_putxx(va_arg(args, unsigned int)));*/
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
				ret += write(1, "%", 1);
			else
				ret += print_variable(args, *format);
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

int main(void)
{
	char c = 'c';
	ft_printf("%c", c);
}
