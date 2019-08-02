/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/02 21:52:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void get_format1(const char **str, t_format *format, va_list argptr)
{
	format->presence_dot = **str == '.';
	*str += **str == '.';
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

void get_format(const char **str, t_format *format, va_list argptr)
{
	ft_memset(format, 0, sizeof(t_format));
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
	while (**str == '*' || ft_isdigit(**str))
		++*str;
	get_format1(str, format, argptr);
}

void print_digital(t_buf *buf, t_format *format, int num)
{
	char *res;
	char *iter;
	size_t size;
	size_t i;
	size_t num_size;

	if (!buf)
		return ;
	num_size = sizeof_num(num, 10);
	size = ft_max(3, format->width, format->precision, num_size);
	if (!(res = ft_strnew(size)))
		return ;
	iter = res;
	if (format->width && (format->flag_plus || format->flag_space))
		--format->width;
	i = format->width;
	while (!format->flag_minus && i > (unsigned)ft_max(2, format->precision, num_size))
	{
		*iter++ = ' ';
		--i;
	}
	if (num < 0)
	{
		*iter++ = '-';
		num = -num;
	}
	else if (format->flag_plus)
		*iter++ = '+';
	else if (format->flag_space)
		*iter++ = ' ';
	i = format->precision;
	while (i > num_size)
	{
		*iter++ = '0';
		--i;
	}
	while (num)
	{
		*iter++ = '0' + num % 10;
		num /= 10;
	}
	ft_strrev(iter - num_size);
	while (format->flag_minus && format->width > (unsigned)ft_max(2, format->precision, num_size))
	{
		*iter++ = ' ';
		--format->width;
	}
	printf("|%s|\n", res);
}

void				print_arg(const char **str, va_list argptr, t_buf *buf)
{
	t_format	format;

	get_format(str, &format, argptr);
	// printf("flag_minus: %u\n", format.flag_minus);
	// printf("flag_plus: %u\n", format.flag_plus);
	// printf("flag_space: %u\n", format.flag_space);
	// printf("flag_zero: %u\n", format.flag_zero);
	// printf("flag_hash: %u\n", format.flag_hash);
	// printf("precision: %u\n", format.precision);
	// printf("dot_presence: %u\n", format.presence_dot);
	// printf("width: %u\n", format.width);
	// printf("type: %c\n", format.type);
	// printf("modifier: %u\n", format.modificate);
	if (format.type == 'i' || format.type == 'd')
		print_digital(buf, &format, va_arg(argptr, int));
}

void add_in_buf(t_buf *buf, const char *str, size_t n)
{
	if (n > BUFF_SIZE)
	{
		write(1, str, n);
		buf->return_value += n;
		return ;
	}
	if (buf->pos + n >= BUFF_SIZE)
	{
		write(1, buf->buf, buf->pos);
		buf->return_value += buf->pos;
		buf->pos = 0;
	}
	ft_memcpy(buf->buf + buf->pos, str, n);
	buf->pos += n;
}

int 		print(const char *str, va_list argptr)
{
	const char	*prev_pos;
	t_buf		buf;

	prev_pos = str;
	buf.return_value = 0;
	buf.pos = 0;
	while (*prev_pos)
	{
		while (*str && *str != '%')
			++str;
		add_in_buf(&buf, prev_pos, str - prev_pos);
		if (*str) {
			++str;
			print_arg(&str, argptr, &buf);
		}
		prev_pos = str;
	}
	write(1, buf.buf, buf.pos);
	return (buf.return_value);
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
