#include "printf.h"

void print_char(t_buf *buf, t_format *format, va_list argptr)
{
	char alpha;

	alpha = va_arg(argptr, int);
	if (!format->flag_minus && format->width > 1)
		add_in_buf2(buf, ' ', format->width - 1);
	add_in_buf2(buf, alpha, 1);
	if (format->flag_minus && format->width > 1)
		add_in_buf2(buf, ' ', format->width - 1);
}

void print_string(t_buf *buf, t_format *format, va_list argptr)
{
	char *str;
	size_t str_len;

	if (!(str = va_arg(argptr, char*)))
	{
		add_in_buf(buf, "(null)", 6);
		return ;
	}
	str_len = ft_strlen(str);

	if (!format->dot_presence)
		format->precision = str_len;
	if (format->precision > format->width || format->precision > str_len)
		format->precision = str_len;
	if (str_len > format->precision)
		str_len = format->precision;

	if (!format->flag_minus && format->width > (unsigned)ft_max(format->precision, str_len))
		add_in_buf2(buf, ' ', format->width - ft_max(format->precision, str_len));
	if (!(format->dot_presence && format->precision == 0))
		add_in_buf(buf, str, (unsigned)ft_min(str_len, format->precision));
	if (format->flag_minus && format->width > format->precision)
		add_in_buf2(buf, ' ', format->width - ft_min(format->precision, str_len));
}

void	print_alphas(t_buf *buf, t_format *format, va_list argptr)
{
	if (format->type == 'c')
		print_char(buf, format, argptr);
	else
		print_string(buf, format, argptr);
	// char *ptr;
	// char alpha;

	// ptr = NULL;
	// if (format->type == 'S' || format->modificate == LONG)
	// 	ptr = va_arg(argptr, char*);
	// if (format->modificate == DEFAULT)
	// 	alpha = va_arg(argptr, int);
	// if (buf || alpha || ptr)
	// 	return ;
}