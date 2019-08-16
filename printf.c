/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/15 23:21:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



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



void				print_arg(const char **str, va_list argptr, t_buf *buf)
{
	t_format	format;

	get_format(str, &format, argptr);
	if (format.type == 'i' || format.type == 'd' || format.type == 'o' ||
		format.type == 'u' || format.type == 'x' || format.type == 'X')
		print_digital(buf, &format, argptr);
	else if (format.type == 'c' || format.type == 's' || format.type == 'S')
		print_alphas(buf, &format, argptr);
	else if (format.type == 'p')
		print_pointer(buf, &format, argptr);
	else if (format.type == 'f')
		print_float(&format, argptr);
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
		if (*str == '%' && *(str + 1) == '%')
		{
			add_in_buf2(&buf, '%', 1);
			str += 2;
		}
		else if (*str)
		{
			++str;
			print_arg(&str, argptr, &buf);
		}
		prev_pos = str;
	}
	write(1, buf.buf, buf.pos);
	return (buf.return_value + buf.pos);
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
