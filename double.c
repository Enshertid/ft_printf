#include "ft_printf.h"

void		parse_double(long double *d, t_double *num)
{
	ft_memset(num, 0, sizeof(t_double));
	*(char*)&(num->exp) = *((char*)d + 8);
	*((char*)&(num->exp) + 1) = *((char*)d + 9);
	if (num->exp & 32768)
	{
		num->sign = 1;
		num->exp &= 32767;
	}
	else
		num->sign = 0;
	num->mantissa = *((ull*)d);
	num->exp -= 16382;
	if (*d != *d)
		num->is_nan = 1;
	else if (*d && *d == (*d * 10))
		num->is_inf = 1;
}

void		mult(char *str, unsigned long multiplier)
{
	unsigned long	add;
	unsigned long	add_prev;
	unsigned long	cur;

	add = 0;
	while (*(str) || add)
	{
		if (*str)
			*str -= '0';
		cur = (*str * multiplier) + add;
		add_prev = cur / 10;
		*str = '0' + cur % 10;
		add = add_prev;
		--str;
	}
}

void		add(char *str, char *plus)
{
	int add;
	int add_prev;
	int temp;

	add = 0;
	while (*plus || add)
	{
		if (*str != '.')
		{
			if (*str)
				*str -= '0';
			temp = *str + *plus + add;
			if (*plus)
				temp -= '0';
			add_prev = temp / 10;
			*str = '0' + temp % 10;
			add = add_prev;
			if (*plus)
				--plus;
		}
		--str;
	}
}

int						offset(int i)
{
	return ((i / 10) * 3 +
			((i % 10) / 4 ? 1 : 0) +
			((i % 10) / 7 ? 1 : 0) +
			(i / 970 - 1 + (i % 970 != 0)) + 
			(i > 16380));
			// (i > 970) + (i > 1940) + (i > 2910) + (i > 3880) + (i > 4850) + (i > 5820) + (i > 6790) + (i > 7760));
			// ((i % 10) / 7 ? 1 : 0) +
			// (i > 146));
}

void		get_integer_part(char *num, t_double info, t_spec *format)
{
	char *int_begin;

	*num = (info.sign ? '-' : 0);
	*num = (!*num && format->flag_space ? ' ' : *num);
	*num = (*num != '-' && format->flag_plus ? '+' : *num);
	num = num + INT_PART + 1 + (*num != 0);
	if (info.exp <= 0)
		ft_itoa_buf(0, num, 10, 0);
	else
	{
		info.mantissa >>= (64 - (info.exp > 64 ? 64 : info.exp - 64));
		ft_itoa_buf(info.mantissa, num - sizeof_num(info.mantissa, 10) + 1,
					10, 0);
	}
	info.exp = (info.exp > 64 ? info.exp - 64 : 0);
	while (info.exp)
	{
		mult(num, info.exp > 59 ? 1152921504606846976 : 2);
		info.exp -= (info.exp > 59 ? 60 : 1);
	}
	// copy number to head of the string
	int_begin = ft_memrchr(num, 0, INT_PART) + 1;
	ft_memcpy(num - INT_PART, int_begin, ft_strlen(int_begin));
}

void get_fract_part(char *num, t_double info)
{
	char	*plus;
	char	*plus_begin;
	int		iter;

	num = ft_memchr(num + 2, 0, DBL_SIZE);
	*num = '.';
	plus = ft_memalloc(DBL_SIZE);
	plus[DBL_SIZE - 2] = '5';
	iter = 1;
	// skip integer part in mantissa | 		Do it smaller!
	while (info.exp > 0)
	{
		// mult(plus + DBL_SIZE - 2, 5);
		info.mantissa <<= 1;
		--info.exp;
		// ++iter;
	}
	print_bits(&info.mantissa, 8);
	write(1, "\n", 1);
	while (info.exp < 0)
	{
		++iter;
		mult(plus + DBL_SIZE - 2, 5);
		++info.exp;
	}
	plus_begin = plus + DBL_SIZE - 2;
	while (info.mantissa)
	{
		if (info.mantissa >> 63)
		{
			plus_begin = ft_memrchr(plus_begin, 0, DBL_SIZE) + 1;
			add(num + offset(iter) + ft_strlen(plus_begin), plus + DBL_SIZE - 2);
		}
		info.mantissa <<= 1;
		mult(plus + DBL_SIZE - 2, 5);
		++iter;
	}
	*(char*)ft_memchr(num, 0, DBL_SIZE) = '\0';
}

char		*double_to_str(long double d, t_spec *format)
{
	char		*num;
	t_double	num_info;

	if (!format)
		return (NULL);
	num = ft_memalloc(DBL_SIZE);
	parse_double(&d, &num_info);
	get_integer_part(num, num_info, format);
	get_fract_part(num, num_info);
	// write(1, "\n\n\nDEBUG: ", 10);
	// for (int i = 0; i < DBL_SIZE; ++i)
	// {
	// 	if (num[i])
	// 		write(1, num + i, 1);
	// 	else
	// 		write(1, "o", 1);
	// }
	// write(1, "\n\n\n", 3);
	return (num);
}

char		*get_double(const char **str, va_list argptr, t_spec *format)
{
	char *res;

	++(*str);
	if (format->mod == LONG_DOUBLE)
		res = double_to_str(va_arg(argptr, long double), format);
	else
		res = double_to_str(va_arg(argptr, double), format);
	return (res);
}