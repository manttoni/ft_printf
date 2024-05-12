/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:28:44 by amaula            #+#    #+#             */
/*   Updated: 2024/05/12 16:31:30 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putuint(unsigned int ui)
{
	unsigned long	lui;

	lui = (unsigned long) ui^0;
	return (ft_putdec(lui));
}
