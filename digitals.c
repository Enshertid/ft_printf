#include "printf.h"

void print_digital(t_buf *buf, t_format *format, va_list argptr)
{
	size_t num_size;
	unsigned base;
	__int128_t num;
	char cnum[20];

	base = 10;
	if (format->type == 'o')
		base = 8;
	else if (format->type == 'x' || format->type == 'X')
		base = 16;
	if (format->modificate == DEFAULT || format->modificate == CHAR || format->modificate == SHORT)
		num = va_arg(argptr, int);
	else if (format->modificate == LONG)
		num = va_arg(argptr, long);
	else if (format->modificate == LONG_LONG)
		num = va_arg(argptr, long long);

	if (format->type == 'd' || format->type == 'i')
	{
		if (format->modificate == DEFAULT)
			num = (int)num;
		else if (format->modificate == CHAR)
			num = (char)num;
		else if (format->modificate == SHORT)
			num = (short)num;
		else if (format->modificate == LONG)
			num = (long)num;
		else if (format->modificate == LONG_LONG)
			num = (long long)num;
	}
	else if (format->type == 'o' || format->type == 'x' || format->type == 'X' || format->type == 'u')
	{
		if (format->modificate == DEFAULT)
			num = (unsigned)num;
		else if (format->modificate == CHAR)
			num = (unsigned char)num;
		else if (format->modificate == SHORT)
			num = (unsigned short)num;
		else if (format->modificate == LONG)
			num = (unsigned long)num;
		else if (format->modificate == LONG_LONG)
			num = (unsigned long long)num;
	}

	num_size = sizeof_num(num, base);
	ft_itoa(num, cnum, base, format->type == 'X');




	if (!format->flag_zero || format->flag_minus)
	{
		if (format->width > (unsigned)ft_max(num_size, format->precision))
			format->width -= ft_max(num_size, format->precision);
		else
			format->width = 0;
		if (format->width && base == 10 && format->type != 'u' && (num < 10 || format->flag_space || format->flag_plus))
			--format->width;
		if (base == 16 && format->width > 1 && format->flag_hash)
			format->width -= 2;
		if (base == 8 && format->width && format->flag_hash && format->precision <= num_size)
			--format->width;
	}
	else
	{
		if (!format->dot_presence)
		{
			if (format->width > num_size)
			{
				format->precision = format->width;
				// format->width = 0;
				if (format->precision > num_size)
					format->precision -= num_size;
				else
					format->precision = 0;
				if (base == 16 && format->flag_hash && format->precision > 1)
					format->precision -= 2;
				if (base == 8 && format->flag_hash && format->precision > num_size)
					--format->precision;
				if (base == 10 && num < 0 /* && format->precision > num_size */)
					--format->precision;
			}
			format->width = 0;
		}
	}
	
	if (!format->flag_minus && format->width)
		add_in_buf2(buf, ' ' , format->width);

	if (num < 0)
		add_in_buf2(buf, '-', 1);
	else if (base == 10 && format->type != 'u' && format->flag_plus)
		add_in_buf2(buf, '+', 1);
	else if (base == 10 && format->type != 'u' && format->flag_space)
		add_in_buf2(buf, ' ', 1);

	if (base == 16 && format->flag_hash)
		add_in_buf(buf, format->type == 'X' ? "0X" : "0x", 2);
	if (base == 8 && format->flag_hash)
		add_in_buf2(buf, '0', 1);
	if (format->precision)
		add_in_buf2(buf, '0', format->precision);
	add_in_buf(buf, cnum + (cnum[0] == '-'), num_size);
	
	if (format->flag_minus && format->width)
		add_in_buf2(buf, ' ' , format->width);
	
	// if (format->width && base == 10 && (format->flag_space || format->flag_plus || cnum[0] == '-') && (format->type == 'd' || format->type == 'i'))
	// 	--format->width;
	// if (base == 8 && format->flag_hash && (num_size > format->precision))
	// 	format->precision = num_size + 1;
	// 	// ++format->precision;
	// if (!num && format->dot_presence && !format->precision)
	// 	++format->width;
	// if (base == 16 && format->flag_hash && format->width > 2 && num)
	// 	format->width -= 2;

	// if (!format->flag_minus && !format->flag_zero && format->width > format->precision && format->width > num_size)
	// 	add_in_buf2(buf, ' ', format->width - ft_max(format->precision, num_size));
	
	// if (cnum[0] == '-')
	// 	add_in_buf2(buf, '-', 1);
	// else if (base == 10 && format->flag_plus && (format->type == 'd' || format->type == 'i'))
	// 	add_in_buf2(buf, '+', 1);
	// else if (base == 10 && format->flag_space)
	// 	add_in_buf2(buf, ' ', 1);

	// if (base == 16 && format->flag_hash && num)
	// 	add_in_buf(buf, format->type == 'x' ? "0x" : "0X", 2);

	// if (format->precision > num_size)
	// 	add_in_buf2(buf, '0', format->precision - num_size);
	// else if (!format->dot_presence && !format->flag_minus && format->flag_zero && format->width)
	// 	add_in_buf2(buf, '0', format->width - num_size);


	
	// if (!(!num && format->dot_presence && !format->precision))
	// 	add_in_buf(buf, cnum + (cnum[0] == '-'), num_size);

	// if (format->flag_minus && format->width > format->precision && format->width > num_size)
	// 		add_in_buf2(buf, ' ', format->width - ft_max(format->precision, num_size));



	

}





// char *ft_flagsfor_signedzero(t_spec *list, char *numb)
// {
// 	if ((list->flag_plus == 1 || list->flag_space == 1) && list->presence_dot == 0)
// 	{
// 		numb = ft_strnew(2);
// 		if (list->flag_plus == 1)
// 			numb[0] = '+';
// 		else if (list->flag_space == 1)
// 			numb[0] = ' ';
// 		numb[1] = '0';
// 		list->flag_us++;
// 	}
// 	else if ((list->flag_plus == 0 && list->flag_space == 0) && list->presence_dot == 1)
// 		numb = ft_strnew(0);
// 	else if ((list->flag_plus == 1 || list->flag_space == 1) && list->presence_dot == 1)
// 	{
// 		numb = ft_strnew(1);
// 		if (list->flag_plus == 1)
// 			numb[0] = '+';
// 		else if (list->flag_space == 1)
// 			numb[0] = ' ';
// 		list->flag_us++;
// 	}
// 	else
// 	{
// 		numb = ft_strnew(1);
// 		numb[0] = '0';
// 	}
// return (numb);