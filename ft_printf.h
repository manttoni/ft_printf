/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:26:00 by amaula            #+#    #+#             */
/*   Updated: 2024/05/11 19:30:21 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(void *p);
int	ft_putdec(int d);
int	ft_putint(int i);
int	ft_putuint(unsigned int i);
int	ft_puthex(int h);
int	ft_puthex_caps(int hc);

#endif
