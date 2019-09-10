/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:57:15 by user              #+#    #+#             */
/*   Updated: 2019/09/10 23:06:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *get_integer_part(char *str, t_double num)
{
	char	*begin;
	size_t	len;

	*(str - DBL_SIZE + 2) = (num.sign ? '-' : 0);
	if (num.exp < 1)
		ft_itoa(0, str, 10, 0);
	else
	{
		num.mantissa >>= (num.exp < 64 ? 64 - num.exp : 0);
		ft_itoa(num.mantissa, str - sizeof_num(num.mantissa, 10) + 1, 10, 0);
	}
	if (num.exp > 63)
	{
		num.exp -= 64;
		while (num.exp)
		{
			mult(str, num.exp > 31 ? 4294967296 : 2);
			num.exp -= (num.exp > 31 ? 32 : 1);
		}
	}
	begin = ft_memrchr(str, 0, DBL_SIZE) + 1;
	len = ft_strlen(begin);
	ft_memcpy(str - DBL_SIZE + 4, begin, len);
	ft_memset(begin, 0, len);
	return (str);
}

static void get_fract_part(char *str, t_double num)
{
	int		iter;
	char	plus[DBL_SIZE];

	*str++ = '.';
	if (num.exp > 63 || !num.mantissa ||
		(num.exp > 0 && !((num.mantissa <<= num.exp))))
		return ;
	ft_memset(plus, 0, DBL_SIZE);
	plus[DBL_SIZE - 2] = '5';
	iter = 1;
	while (num.exp++ < 0)
	{
		++iter;
		mult(plus + DBL_SIZE - 2, 5);
	}
	evaluate_mantissa(str, plus, num.mantissa, iter);
}

static char *set_precision(char *str, t_format *format)
{
	char	*dot;
	size_t	len;

	if (!format->dot_presence)
		format->width = 6;
	dot = ft_memchr(str, '.', DBL_SIZE);
	len = ft_strlen(dot + 1);
	if (dot - str + format->width + 1 > DBL_SIZE)
	{
		str = expand(str, format->width);
		len = ft_strlen((dot = ft_memchr(str, '.', DBL_SIZE))) - 1;
	}
	if (format->width > len)
		ft_memset(dot + 1 + len, '0', format->width - len);
	else
	{
		if (dot[format->width + 1] > '4')
			add(dot + format->width, "\0001" + 1);
		dot[format->dot_presence && !format->width ?
			0 : format->width + 1] = '\0';
	}
	if (!str[1] && str[0])
		ft_swap(str, str + 1, 1);
	return (str);
}

static char *double_to_str(long double d, t_spec *format)
{
	char		*str;
	t_double	num;
	size_t		len;

	parse_double(&d, &num);
	if (num.is_inf || num.is_nan)
		return (ft_strjoin(num.sign ? "-" : "", num.is_inf ? "inf" : "nan"));
	str = (char*)malloc(DBL_SIZE);
	ft_memset(str, 0, DBL_SIZE);
	get_integer_part(str + DBL_SIZE - 2, num);
	len = ft_strlen(str + 2);
	get_fract_part(str + 2 + len, num);
	str = set_precision(str, format);
	return (str);
}

char *get_double(t_format *format, va_list argptr)
{
	char *str;

	if (format->modificate == LONG_DOUBLE)
		str = double_to_str(va_arg(argptr, long double), format);
	else
		str = double_to_str(va_arg(argptr, double), format);
	// width and precision
	return (str);
}
