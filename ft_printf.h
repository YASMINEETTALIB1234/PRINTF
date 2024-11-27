/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettalib <yettalib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:58 by yettalib          #+#    #+#             */
/*   Updated: 2024/11/19 20:30:41 by yettalib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	int_dicimal_printf(int n);
int	char_printf(int c);
int	str_printf(char *str);
int	hexaprintf(unsigned int n, char c);
int	pointer_printf(unsigned long ptr);
int	unsigned_printf(unsigned int n);

#endif