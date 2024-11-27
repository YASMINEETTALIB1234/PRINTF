/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:29:18 by yettalib          #+#    #+#             */
/*   Updated: 2024/11/19 18:15:24 by yettalib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_digit(unsigned long n)
{
	int		compt;
	char	*base_hexa;

	compt = 0;
	base_hexa = "0123456789abcdef";
	if (n >= 16)
	{
		compt += hex_digit(n / 16);
		compt += hex_digit(n % 16);
	}
	else
	{
		compt += write(1, &base_hexa[n], 1);
	}
	return (compt);
}

int	pointer_printf(unsigned long point)
{
	int	compt;

	compt = 0;
	compt += write(1, "0x", 2);
	if (point == 0)
		compt += write(1, "0", 1);
	else
		compt += hex_digit(point);
	return (compt);
}
