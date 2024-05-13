/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:55:07 by amaula            #+#    #+#             */
/*   Updated: 2024/05/13 12:55:51 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void pl()
{
	printf("\n----------------------\n");
}

void test(char *format, ...)
{
	va_list args;
	va_start(args, format);

	char specifier = format[1];

	if (specifier == 'c')
	{
		char a = va_arg(args, int);
		if (printf(format, a) == ft_printf(format, a))
			printf("\nChar success");
		else
			printf("\nChar fail");
	}
	if (specifier == 's')
	{
		char *s = va_arg(args, char *);
		if (printf(format, s) == ft_printf(format, s))
			printf("\nString success");
		else
			printf("\nString fail");
	}
	if (specifier == 'p')
	{
		void *p = va_arg(args, void *);
		if (printf(format, p) == ft_printf(format, p))
			printf("\nPointer success");
		else
			printf("\nPointer fail");
	}
	if (specifier == 'u')
	{
		unsigned int u = va_arg(args, unsigned int);
		if (printf(format, u) == ft_printf(format, u))
			printf("\nUnsigned integer success");
		else
			printf("\nUnsigned integer fail");
	}
	if (specifier == 'x' || specifier == 'X')
	{
		unsigned long ul = va_arg(args, unsigned long);
		if (printf(format, ul) == ft_printf(format, ul))
			printf("\nHex success");
		else
			printf("\nHex fail");
	}
	if (	specifier == 'd' || 
			specifier == 'i' ) 
	{
		int d = va_arg(args, int);
		if (printf(format, d) == ft_printf(format, d))
			printf("\nInteger success");
		else
			printf("\nInteger fail");
	}
	va_end(args);
	pl();
}


	
int main(void)
{
	pl();
	int i = 1;
	void *p = &i;
	test("%c\n", 'c');
	test("%s\n", "kissa");
	test("%p\n", LONG_MAX);
	test("%d\n", i);
	test("%i\n", 012);
	test("%u\n", (unsigned int)INT_MAX + 1);
	test("%x\n", LONG_MIN);
	test("%X\n", LONG_MAX);
}
