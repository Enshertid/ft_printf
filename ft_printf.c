/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/22 14:53:45 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_type_definition(const char **str,
					t_spec *list, va_list per)
{
	if (**str == 'd' || **str == 'i')
		return (ft_signed_digital(str, list, va_arg(per, int)));
//	else if (**str == 'u')
//		return (ft_unsigned_digital(str, list, va_arg(per, unsigned)));
//	else if (**str == 'o')
//		return (ft_unsigned_octal(str, list, per));
//	else if (**str == 'x')
//		return (ft_hexical_low(str, list, per));
//	else if (**str == 'X')
//		return (ft_hexical_hight(str, list, per));
//	else if (**str == 'c')
//		return (ft_signed_char(str, list, per));
//	else if (**str == 's')
//		return (ft_string_output(str, list, per));
//	else if (**str == 'p')
//		return (ft_pointer_output(str, list, per));
//	else if (**str == 'f')
//		return (ft_signed_float(str, list, per));
	else
	{
		(*str)++;
		return (1);
	}
}

void				ft_check_width_and_precision(const char **str,
										t_spec *list, va_list per)
{
	if (**str == '*')
	{
		list->width = va_arg(per, int);
		list->presence_width = 1;
		(*str)++;
	}
	list->width = ft_atoi(*str);
	while (ft_isdigit(**str))
	{
		list->presence_width = 1;
		(*str)++;
	}
	if (**str == '.')
	{
		list->precision = ft_atoi(++(*str));
		list->presence_dot = 1;
	}
	if (**str == '*')
	{
		list->precision = va_arg(per, int);
		list->presence_precision = 1;
		(*str)++;
	}
}

int					ft_second_step(const char **str, va_list per, t_spec *list)
{
		if (!(ft_check_format(**str)))
			ft_check_flags(str, list, per);
		ft_check_width_and_precision(str, list, per);
		while (ft_isdigit(**str))
		{
			(*str)++;
			list->presence_precision = 1;
		}
		ft_check_modificate(str, list);
		return (ft_type_definition(str, list, per));
}

int 		ft_first_step(const char *str, va_list per)
{
	const char		*output;
	t_spec			*list;
	int				return_value;

	output = str;
	list = ft_list_new();
	return_value = 0;
	while (*str)
	{
		while (*str && *str != '%')
			str++;
		write (1, output, str - output);
		return_value += (str - output);
		if(*str)
		{
			str++;
			return_value += ft_second_step(&str, per, list);
		}
		output = str;
		ft_list_clear(list);
	}
	return (return_value);
}

int 		ft_printf(const char *str, ...)
{
	va_list		per;
	int			return_value;

	va_start(per, str);
	return_value = ft_first_step(str, per);
	va_end(per);
	return (return_value);
}
