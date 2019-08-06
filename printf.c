/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/05 22:22:58 by user             ###   ########.fr       */
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

void add_in_buf2(t_buf *buf, int c, size_t n)
{
	size_t can_write;
	while (n)
	{
		can_write = ft_min(n, BUFF_SIZE - buf->pos);
		ft_memset(buf->buf + buf->pos, c, can_write);
		if ((buf->pos += can_write) == BUFF_SIZE)
		{
			write(1, buf->buf, BUFF_SIZE);
			buf->return_value += BUFF_SIZE;
			buf->pos = 0;
		}
		n -= can_write;
	}
}

void add_in_buf(t_buf *buf, const char *str, size_t n)
{
	size_t can_write;

	while (n)
	{
		can_write = ft_min(n, BUFF_SIZE - buf->pos);
		ft_memcpy(buf->buf + buf->pos, str, can_write);
		if ((buf->pos += can_write) == BUFF_SIZE)
		{
			write(1, buf->buf, BUFF_SIZE);
			buf->return_value += BUFF_SIZE;
			buf->pos = 0;
		}
		str += can_write;
		n -= can_write;
	}
	// if (n > BUFF_SIZE)
	// {
	// 	write(1, str, n);
	// 	buf->return_value += n;
	// 	return ;
	// }
	// if (buf->pos + n >= BUFF_SIZE)
	// {
	// 	write(1, buf->buf, buf->pos);
	// 	buf->return_value += buf->pos;
	// 	buf->pos = 0;
	// }
	// ft_memcpy(buf->buf + buf->pos, str, n);
	// buf->pos += n;
}


// if (format->type != 'u' && (format->modificate == DEFAULT || format->modificate == SHORT || format->modificate == CHAR))
// 		num = va_arg(argptr, int);
// 	else if (format->type != 'u' && format->modificate == LONG)
// 		num = va_arg(argptr, long int);
// 	else if (format->type != 'u' && format->modificate == LONG_LONG)
// 		num = va_arg(argptr, long long int);
// 	else if (format->type == 'u' && (format->modificate == DEFAULT || format->modificate == SHORT || format->modificate == CHAR))
// 		num = va_arg(argptr, unsigned int);
// 	else if (format->type != 'u' && format->modificate == LONG)
// 		num = va_arg(argptr, unsigned long int);
// 	else if (format->type != 'u' && format->modificate == LONG_LONG)
// 		num = va_arg(argptr, unsigned long long int);
// 
// 
// if (format->type != 'u' && format->modificate == DEFAULT)
// 		num = (int)num;
// 	else if (format->type != 'u' && format->modificate == CHAR)
// 		num = (char)num;
// 	else if (format->type != 'u' && format->modificate == SHORT)
// 		num = (short)num;
// 	else if (format->type != 'u' && format->modificate == LONG)
// 		num = (long)num;
// 	else if (format->type != 'u' && format->modificate == LONG_LONG)
// 		num = (long long)num;
// 	else if (format->type == 'u' && format->modificate == DEFAULT)
// 		num = (unsigned int)num;
// 	else if (format->type == 'u' && format->modificate == CHAR)
// 		num = (unsigned char)num;
// 	else if (format->type == 'u' && format->modificate == SHORT)
// 		num = (unsigned short)num;
// 	else if (format->type == 'u' && format->modificate == LONG)
// 		num = (unsigned long)num;
// 	else if (format->type == 'u' && format->modificate == LONG_LONG)
// 		num = (unsigned long long)num;

void print_digital(t_buf *buf, t_format *format, va_list argptr)
{
	size_t num_size;
	unsigned base;
	long long int num;
	char cnum[20];

	if (format->type != 'u' && (format->modificate == DEFAULT || format->modificate == SHORT || format->modificate == CHAR))
		num = va_arg(argptr, int);
	else if (format->type != 'u' && format->modificate == LONG)
		num = va_arg(argptr, long int);
	else if (format->type != 'u' && format->modificate == LONG_LONG)
		num = va_arg(argptr, long long int);
	else if (format->type == 'u' && (format->modificate == DEFAULT || format->modificate == SHORT || format->modificate == CHAR))
		num = va_arg(argptr, unsigned int);
	else if (format->type == 'u' && format->modificate == LONG)
		num = va_arg(argptr, unsigned long int);
	else if (format->type == 'u' && format->modificate == LONG_LONG)
		num = va_arg(argptr, long long int);
//	num = va_arg(argptr, long long int);
	if (format->type == 'i' || format->type == 'd' || format->type == 'u')
		base = 10;
	else if (format->type == 'o')
		base = 8;
	else if (format->type == 'x' || format->type == 'X')
		base = 16;
	if (format->type != 'u' && format->modificate == DEFAULT)
		num = (int)num;
	else if (format->type != 'u' && format->modificate == CHAR)
		num = (char)num;
	else if (format->type != 'u' && format->modificate == SHORT)
		num = (short)num;
	else if (format->type != 'u' && format->modificate == LONG)
		num = (long)num;
	else if (format->type != 'u' && format->modificate == LONG_LONG)
		num = (long long)num;
	else if (format->type == 'u' && format->modificate == DEFAULT)
		num = (unsigned int)num;
	else if (format->type == 'u' && format->modificate == CHAR)
		num = (unsigned char)num;
	else if (format->type == 'u' && format->modificate == SHORT)
		num = (unsigned short)num;
	else if (format->type == 'u' && format->modificate == LONG)
		num = (unsigned long)num;
	num_size = sizeof_num(num, base);
	if (format->type != 'u' && format->modificate == DEFAULT)
		ft_itoa((int)num, cnum, base, format->type == 'X');
	else if (format->type != 'u' && format->modificate == CHAR)
		ft_itoa((char)num, cnum, base, format->type == 'X');
	else if (format->type != 'u' && format->modificate == SHORT)
		ft_itoa((short)num, cnum, base, format->type == 'X');
	else if (format->type != 'u' && format->modificate == LONG)
		ft_itoa((long)num, cnum, base, format->type == 'X');
	else if (format->type != 'u' && format->modificate == LONG_LONG)
		ft_itoa((long long)num, cnum, base, format->type == 'X');
	else if (format->type == 'u' && format->modificate == DEFAULT)
		ft_itoa((unsigned int)num, cnum, base, format->type == 'X');
	else if (format->type == 'u' && format->modificate == CHAR)
		ft_itoa((unsigned char)num, cnum, base, format->type == 'X');
	else if (format->type == 'u' && format->modificate == SHORT)
		ft_itoa((unsigned short)num, cnum, base, format->type == 'X');
	else if (format->type == 'u' && format->modificate == LONG)
		ft_itoa((unsigned long)num, cnum, base, format->type == 'X');
	else if (format->type == 'u' && format->modificate == LONG_LONG)
		ft_itoa((unsigned long long)num, cnum, base, format->type == 'X');
	if (format->width && base == 10 && (num < 0 || format->flag_plus || format->flag_space))
		--format->width;
	else if (format->width > 1 && base == 16 && format->flag_hash)
		format->width -= 2;
	else if (base == 8 && format->flag_hash && format->width && num_size >= format->precision)
		--format->width;
	if (!format->flag_minus && format->width > (unsigned)ft_max(format->precision, num_size))
		add_in_buf2(buf, ' ', format->width - ft_max(format->precision, num_size));
	if (base == 10 && num < 0)
		add_in_buf2(buf, '-', 1);
	else if (format->flag_plus)
		add_in_buf2(buf, '+', 1);
	else if (format->flag_space)
		add_in_buf2(buf, ' ', 1);
	if (base == 16 && format->flag_hash)
		add_in_buf(buf, format->type == 'x' ? "0x" : "0X", 2);
	if (format->precision > num_size)
		add_in_buf2(buf, '0', format->precision - num_size);
	if (base == 8 && format->flag_hash && num_size >= format->precision)
		add_in_buf2(buf, '0', 1);
	add_in_buf(buf, cnum + (cnum[0] == '-'), num_size + (base == 10 && num < 0));
	if (format->flag_minus && format->width > (unsigned)ft_max(format->precision, num_size))
		add_in_buf2(buf, ' ', format->width - ft_max(format->precision, num_size));
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
	if (format.type == 'i' || format.type == 'd' || format.type == 'o' || format.type == 'u' || format.type == 'x' || format.type == 'X')
		print_digital(buf, &format, argptr);
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
