#include "ft_printf.h"

void							parse_double(long double *d, t_double *num)
{
	// write(1, "orig: ", 6);
	// printn_bits(d, 10);
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
	num->mantissa = *((ULL*)d);
	num->exp -= 16382;
	if (*d != *d)
		num->is_nan = 1;
	else if (*d && *d == (*d * 10))
		num->is_inf = 1;
	// write(1, "my:   ", 6);
	// print_bits(&num->exp, 2);
	// printn_bits(&num->mantissa, 8);
}

void						mult(char *str, unsigned long multiplier)
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

void			add(char *str, char *plus)
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

char *get_integer_part(char *str, t_double num, t_spec *list)
{
	static int i = 0;
	++i;
	*(str - DBL_SIZE + 2) = (num.sign ? '-' : 0);
	if (!*(str - DBL_SIZE + 2) && list->flag_space)
		*(str - DBL_SIZE + 2) = ' ';
	if (*(str - DBL_SIZE + 2) != '-' && list->flag_plus)
		*(str - DBL_SIZE + 2) = '+';
	if (num.exp < 1)
		ft_itoa_buf(0, str, 10, 0);
	else
	{
		num.mantissa >>= (num.exp < 64 ? 64 - num.exp : 0);
		ft_itoa_buf(num.mantissa, str - sizeof_num(num.mantissa, 10) + 1, 10, 0);
	}
	if (num.exp < 65)
		return (ft_memrchr(str, 0, INT_PART) + 1);
	num.exp -= 64;
	while (num.exp)
	{
		mult(str, num.exp > 31 ? 4294967296 : 2);
		num.exp -= (num.exp > 31 ? 32 : 1);
	}
	return (ft_memrchr(str, 0, INT_PART) + 1);
}

int						offset(int i)
{
	return ((i / 10) * 3 +
			((i % 10) / 4 ? 1 : 0) +
			((i % 10) / 7 ? 1 : 0) +
			(i / 970 - 1 + (i % 970 != 0)) + 
			(i > 16380));
}

void					evaluate_mantissa(char *str, char *plus, ULL mantissa, int iter)
{
	char	*plus_head;

	plus_head = plus + DBL_SIZE - 2;
	while (mantissa)
	{
		if (mantissa >> 63)
		{
			plus_head = ft_memrchr(plus_head, 0, DBL_SIZE) + 1;
			add(str + offset(iter) + ft_strlen(plus_head) - 1, plus + DBL_SIZE - 2);
		}
		if ((mantissa <<= 1))
			mult(plus + DBL_SIZE - 2, 5);
		++iter;
	}
	while (!*str)
		*str++ = '0';
}

void				get_fract_part(char *str, t_double num)
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

char				*expand_str(char *str, size_t size)
{
	char *new;
	size_t len;
	size_t new_size;

	len = ft_strlen(str + 2) + 2;
	new_size = (char*)ft_memchr(str, '.', DBL_SIZE) - str + size + 2;
	if (new_size > 20000)
		new_size = 20000;
	new = (char*)malloc(new_size);
	ft_memcpy(new, str, len);
	ft_memset(new + len, 0, new_size - len);
	free(str);
	return (new);
}

char				*set_precision(char *str, t_spec *format)
{
	char	*dot;
	size_t	len;

	if (!format->presence_dot)
		format->precision = 6;
	if (format->precision > 214748199)
		format->precision = 214748199;
	format->precision = (format->precision > INT_MAX ? INT_MAX : format->precision);
	dot = ft_memchr(str, '.', DBL_SIZE);
	len = ft_strlen(dot + 1);
	// if (dot - str + format->precision + 1 > DBL_SIZE)
	// {
	// 	str = expand_str(str, format->precision);
	// 	len = ft_strlen((dot = ft_memchr(str, '.', DBL_SIZE))) - 1;
	// }
	if (dot - str + format->precision + 1 > DBL_SIZE)
		format->precision = DBL_SIZE - (dot - str) + 1;
	if (format->precision > len)
		ft_memset(dot + 1 + len, '0', format->precision - len);
	else
	{
		if (dot[format->precision + 1] > '4')
			add(dot + format->precision, "\0001" + 1);
		dot[!format->flag_hash && format->presence_dot && !format->precision ?
			0 : format->precision + 1] = '\0';
	}
	if (!str[1] && str[0])
		ft_swap(str, str + 1, 1);
	return (str);
}

char *double_to_str(long double d, t_spec *format)
{
	char		*str;
	t_double	num;
	size_t		len;
	char		*iter;

	parse_double(&d, &num);
	if (num.is_inf || num.is_nan)
	{
		if (num.sign)
			return (ft_strjoin("-", num.is_inf ? "inf" : "nan"));
		if (format->flag_plus)
			return (ft_strjoin("+", num.is_inf ? "inf" : "nan"));
		if (format->flag_space)
			return (ft_strjoin(" ", num.is_inf ? "inf" : "nan"));
		return (ft_strjoin("", num.is_inf ? "inf" : "nan"));
	}
	str = (char*)malloc(DBL_SIZE);
	ft_memset(str, 0, DBL_SIZE);
	iter = get_integer_part(str + DBL_SIZE - 2, num, format);
	len = ft_strlen(iter);
	ft_memcpy(str + 2, iter, len);
	ft_memset(iter, 0, len);
	get_fract_part(str + 2 + len, num);
	str = set_precision(str, format);
	return (str);
}