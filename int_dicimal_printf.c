/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dicimal_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:56:55 by yettalib          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:04 by yettalib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_dicimal_printf(int nbr)
{
	char	*base_decimal;
	long	nb;
	int		compt;

	nb = nbr;
	base_decimal = "0123456789";
	compt = 0;
	if (nb < 0)
	{
		compt += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		compt += int_dicimal_printf(nb / 10);
		compt += int_dicimal_printf(nb % 10);
	}
	else
	{
		compt += char_printf(base_decimal[nb]);
	}
	return (compt);
}
