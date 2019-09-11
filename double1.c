/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:49:41 by user              #+#    #+#             */
/*   Updated: 2019/09/11 11:09:10 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void parse_double(long double *d, t_double *num)
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

void mult(char *str, unsigned long multiplier)
{
	unsigned long	add;
	unsigned long	add_prev;
	unsigned long	cur;

	add = 0;
	add_prev = 0;
	while (*(str) || add)
	{
		if (*str)
			*str -= '0';
		cur = (*str * multiplier) + add;
		add_prev = cur / 10;
		*str = '0' + cur % 10;
		add = add_prev;
		add_prev = 0;
		--str;
	}
}


void add(char *str, char *plus)
{
	int add;
	int add_prev;
	int temp;

	add = 0;
	add_prev = 0;
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
			add_prev = 0;
			if (*plus)
				--plus;
		}
		--str;
	}
}



 int offset(int i)
 {
 	return ((i / 10) * 3 +
 			((i % 10) / 4 ? 1 : 0) +
 			((i % 10) / 7 ? 1 : 0) +
 			(i > 146));
 }

void evaluate_mantissa(char *str, char *plus, ull mantissa, int iter)
{
	char	*plus_head;
	int		offset;

	plus_head = plus + DBL_SIZE - 2;
	while (mantissa)
	{
		if (mantissa >> 63)
		{
			plus_head = ft_memnchr(plus_head, 0, DBL_SIZE) + 1;
			offset = (iter / 10) * 3 + ((iter % 10) / 4 ? 1 : 0) +
					((iter % 10) / 7 ? 1 : 0) + (iter > 146);
			add(str + offset + ft_strlen(plus_head) - 1, plus + DBL_SIZE - 2);
		}
		if ((mantissa <<= 1))
			mult(plus + DBL_SIZE - 2, 5);
		print_bits(&mantissa, 8);
		write(1, "\n", 1);
		++iter;
	}
	while (!*str)
		*str++ = '0';
}



char *expand(char *str, size_t size)
{
	char *new;
	size_t len;
	size_t new_size;

	len = ft_strlen(str + 2) + 2;
	new_size = (char*)ft_memchr(str, '.', DBL_SIZE) - str + size + 2;
	new = (char*)malloc(new_size);
	ft_memcpy(new, str, len);
	ft_memset(new + len, 0, new_size - len);
	free(str);
	return (new);
}