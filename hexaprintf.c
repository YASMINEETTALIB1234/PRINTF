/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HexaPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:10:51 by yettalib          #+#    #+#             */
/*   Updated: 2024/11/19 18:07:35 by yettalib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexaprintf(unsigned int nbr, char x_X)
{
	int		compt;
	char	*base_hexa;

	if (x_X == 'X')
		base_hexa = "0123456789ABCDEF";
	else if (x_X == 'x')
		base_hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (hexaprintf(-nbr, x_X) + 1);
	}
	else if (nbr < 16)
	{
		return (char_printf(base_hexa[nbr]));
	}
	else
	{
		compt = hexaprintf(nbr / 16, x_X);
		return (compt + hexaprintf(nbr % 16, x_X));
	}
}
