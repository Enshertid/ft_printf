/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:59:11 by dbendu            #+#    #+#             */
/*   Updated: 2019/09/11 19:52:40 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_binary_output(t_spec *format, void *ptr)
{
	char *str;
	size_t len;
	size_t pos;
	int byte;
	int offset;

	len = ft_max(format->width, format->precision) * 8 +
		  ft_max(format->width, format->precision);
	str = (char*)malloc(len);
	byte = ft_max(format->width, format->precision);
	while (byte--)
		ft_memcpy(str + byte * 8 + byte, "00000000 ", 9);
	pos = format->flag_minus * (format->width - format->precision) * 9;
	if (pos > len)
		pos = 0;
	byte = format->precision;
	while (--byte >= 0)
	{
		offset = 8;
		while (--offset >= 0)
			str[pos++] = '0' + ((*((char*)ptr + byte) >> offset) & 1);
		str[pos++] = ' ';
	}
	str[len - 1] = '\0';
	return (str);
}


