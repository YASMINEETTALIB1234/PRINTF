/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:25:36 by yettalib          #+#    #+#             */
/*   Updated: 2024/11/19 18:06:56 by yettalib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_printf(unsigned int nbr)
{
	int		compt;
	char	*base_int;

	base_int = "0123456789";
	if (nbr >= 10)
	{
		compt = int_dicimal_printf(nbr / 10);
		return (compt + int_dicimal_printf(nbr % 10));
	}
	else
	{
		return (char_printf(base_int[nbr]));
	}
}
