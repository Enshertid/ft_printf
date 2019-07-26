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

int					ft_type_definition(const char **str, va_list per, t_spec *list)
{
	(*str)++;
	return (1);
}

int					ft_second_step(const char **str, va_list per, t_spec *list)
{
		if (!(ft_check_format(**str)))
			ft_check_flags(str, list);
		list->width = ft_atoi(*str);
		if (**str == '*')
		{
			list->width = va_arg(per, int);
			(*str)++;
		}
		while (ft_isdigit(**str))
			(*str)++;
		if (**str == '.')
			list->precision = ft_atoi(++(*str));
		if (**str == '*')
		{
			list->precision = va_arg(per, int);
			(*str)++;
		}
		while (ft_isdigit(**str))
			(*str)++;
		ft_check_modificate(str, list);
		return (ft_type_definition(str, per, list));
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
		str++;
		if(*str)
			return_value += ft_second_step(&str, per, list);
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
