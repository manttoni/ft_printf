/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:33:31 by amaula            #+#    #+#             */
/*   Updated: 2024/05/11 20:50:40 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned int h)
{
	char	digit;
	int 	ret;
	int 	tmp;

	ret = 0;
	if (h >= 16)
	{
		tmp = ft_puthex(h / 16);
		if (tmp < 0)
			return (-1);
		ret += tmp;
	}
	digit = h % 16 + '0';
	if (digit > '9')
		digit += 39;
	tmp = ft_putchar(digit);
	if (tmp < 0)
		return (-1);
	return (ret + tmp);
}
