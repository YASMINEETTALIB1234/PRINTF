/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:52 by yettalib          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:39 by yettalib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_printf(char Format_type, va_list list)
{
	int	compt;

	compt = 0;
	if (Format_type == 'c')
		compt += char_printf(va_arg(list, int));
	else if (Format_type == 's')
		compt += str_printf(va_arg(list, char *));
	else if (Format_type == 'd' || Format_type == 'i')
		compt += int_dicimal_printf(va_arg(list, int));
	else if (Format_type == 'x' || Format_type == 'X')
		compt += hexaprintf(va_arg(list, unsigned int), Format_type);
	else if (Format_type == 'p')
		compt += pointer_printf(va_arg(list, unsigned long));
	else if (Format_type == '%')
		compt += char_printf('%');
	else if (Format_type == 'u')
		compt += unsigned_printf(va_arg(list, unsigned int));
	else
		compt += write(1, &Format_type, 1);
	return (compt);
}

int	ft_printf(const char *format_type, ...)
{
	va_list	list;
	int		compt;

	if (write (1, "", 0) == -1)
		return (-1);
	va_start(list, format_type);
	compt = 0;
	while (*format_type != '\0')
	{
		if (*format_type == '%')
			compt += ft_format_printf(*(++format_type), list);
		else
			compt += write(1, format_type, 1);
		format_type++;
	}
	va_end(list);
	return (compt);
}
