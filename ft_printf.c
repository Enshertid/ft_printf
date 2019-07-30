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



void get_format1(const char **str, t_spec *format, va_list argptr)
{
	format->presence_dot = **str == '.';
	*str += **str == '.';
	if (**str == '*' || ft_isdigit(**str))
		format->presence_precision = 1;
	format->precision = ft_atoi(*str);
	if (**str == '*')
		format->precision = va_arg(argptr, int);
	while (**str == '*' || ft_isdigit(**str))
		++*str;
	if (**str == 'h' && *(*str + 1) == 'h')
		format->modificate = CHAR;
	else if (**str == 'h')
		format->modificate = SHORT;
	else if (**str == 'l' && *(*str + 1) == 'l')
		format->modificate = LONG_LONG;
	else if (**str == 'l')
		format->modificate = LONG;
	else if (**str == 'L')
		format->modificate = LONG_DOUBLE;
	while (**str == 'h' || **str == 'l' || **str == 'L')
		++*str;
	format->type = **str;
	++*str;
}

void get_format(const char **str, t_spec *format, va_list argptr)
{
	ft_memset(format, 0, sizeof(t_spec));
	while (**str == '-' || **str == '+' || **str == ' ' ||
			**str == '#' || (**str == '0' && !format->flag_zero))
	{
		if (**str == '-')
			format->flag_minus = 1;
		else if (**str == '+')
			format->flag_plus = 1;
		else if (**str == ' ')
			format->flag_space = 1;
		else if (**str == '#')
			format->flag_hash = 1;
		else if (**str == '0')
			format->flag_zero = 1;
		++*str;
	}
	format->width = ft_atoi(*str);
	if (**str == '*')
		format->width = va_arg(argptr, int);
	if (**str == '*' || ft_isdigit(**str))
		format->presence_width = 1;
	while (**str == '*' || ft_isdigit(**str))
		++*str;
	get_format1(str, format, argptr);
}

int					print_arg(const char **str, va_list argptr)
{
	int		return_value;
	t_spec	format;

//	va_arg(argptr, int);

	get_format(str, &format, argptr);
	return_value = 0;
	printf("flag_minus: %u\n", format.flag_minus);
	printf("flag_plus: %u\n", format.flag_plus);
	printf("flag_space: %u\n", format.flag_space);
	printf("flag_zero: %u\n", format.flag_zero);
	printf("flag_hash: %u\n", format.flag_hash);
	printf("precision: %u\n", format.precision);
	printf("precision_presence: %u\n", format.presence_precision);
	printf("dot_presence: %u\n", format.presence_dot);
	printf("width_presence: %u\n", format.presence_width);
	printf("width: %u\n", format.width);
	printf("type: %c\n", format.type);
	printf("modifier: %u\n", format.modificate);

	return (return_value);
}

int 		print(const char *str, va_list argptr)
{
	const char		*prev_pos;
	int				return_value;

	prev_pos = str;
	return_value = 0;
	while (*prev_pos)
	{
		while (*str && *str != '%')
			++str;
		write(1, "***\n", 4);
		write (1, prev_pos, str - prev_pos);
		write(1, "\n***\n", 5);
		return_value += str - prev_pos;
		if (*str) {
			++str;
			return_value += print_arg(&str, argptr);
		}
		prev_pos = str;
	}
	return (return_value);
}

int 		ft_printf(const char *str, ...)
{
	va_list		argptr;
	int			return_value;

	va_start(argptr, str);
	return_value = print(str, argptr);
	va_end(argptr);
	return (return_value);
}
