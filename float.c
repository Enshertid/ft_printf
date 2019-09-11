/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:59:11 by dbendu            #+#    #+#             */
/*   Updated: 2019/09/11 17:03:11 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void print_bits(void *a, size_t size, t_spec *list)
//{
//	char *str_out;
//	size_t pos;
//	int byte;
//	int offset;
//
//	if (list->width > size)
//	{
//		str_out = (ft_strnew(list->width * 8 + list->width - 1));
//		ft_memset (str_out, ' ', ft_strlen(str_out));
//	}
//	else
//		str_out = (ft_strnew(size * 8 + size - 1));
//	pos = 0;
//	byte = size;
//	while (--byte >= 0)
//	{
//		offset = 8;
//		while (--offset >= 0)
//			buf[pos++] = '0' + ((*((char*)a + byte) >> offset) & 1);
//		buf[pos++] = ' ';
//	}
//	write(1, buf, size * 8 + size);
//}

//char				*ft_before_dot(double per, t_spec *list)
//{
//	char *str;
//	char *str_out;
//
//	str = ft_strnew(6);
//	str_out = str;
//	*str++ = '1';
//	*str++ = '4';
//	ft_memset(str, '0', 4);
//	return (str_out);
//}
//
//char				*ft_after_dot(double numb, t_spec *list)
//{
//	char *str;
//	char *str_out;
//
//	str = ft_strnew(2);
//	str_out = str;
//	*str++ = '3';
//	*str = '.';
//	return (str_out);
//}
//
//char				*ft_float_width(char *before, char *after, t_spec *list, int ln)
//{
//	size_t			i;
//	size_t			j;
//	char		*str_out;
//
//	i = 0;
//	j = 0;
//	str_out = ft_strnew(list->width);
//	if (list->flag_zero == 1 && list->flag_minus == 0)
//		ft_memset(str_out, '0', list->width);
//	else
//		ft_memset(str_out, ' ', list->width);
//	if (list->flag_minus == 1)
//		i += list->width - ln;
//	while (str_out[i])
//	{
//		while(before[j] && str_out[i])
//			str_out[i++] = before[j++];
//		j = 0;
//		while (after[j] && str_out[i])
//			str_out[i++] = before[j++];
//	}
//	return (str_out);
//}
//
char				*ft_float(const char **str, va_list per, t_spec *list)
{
	char		*str_out;

	if (list->mod == LONG_DOUBLE)
		str_out = get_double(va_arg(per, long double), list);
	else
		str_out = get_double(va_arg(per, double), list);

//	str_out = get_double(list, per);
	(*str)++;
	return(str_out);
}
