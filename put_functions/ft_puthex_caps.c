/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:57:17 by amaula            #+#    #+#             */
/*   Updated: 2024/05/13 12:35:53 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex_caps(unsigned int hc)
{
	char	digit;
	int 	ret;
	int 	tmp;

	ret = 0;
	if (hc >= 16)
	{
		tmp = ft_puthex_caps(hc / 16);
		if (tmp < 0)
			return (-1);
		ret += tmp;
	}
	digit = hc % 16;
	if (digit >= 10)
		digit += 'A' - 10;
	else
		digit += '0';
	tmp = ft_putchar(digit);
	if (tmp < 0)
		return (-1);
	return (ret + tmp);
}
