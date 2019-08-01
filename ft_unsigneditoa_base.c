//
// Created by Yaxley Manilow on 2019-08-01.
//

#include "ft_printf.h"
#include <stdio.h>

unsigned	ft_checklenght(unsigned num, int base)
{
	unsigned		i;

	i = 0;
	while (num /= base)
		i++;
	return (i + 1);
}

char		*ft_unsigned_itoa_base(long long unsigned int num,int baze , unsigned size)
{
	char						*s;
	char						*base;
	unsigned					lenght;

	lenght =ft_checklenght(num, baze);
	if (baze == 16)
		base = (size == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	else if (baze == 8)
		base = "01234567";
	else if (baze == 10)
		base = "0123456789";
	else
		return ("check base");
	s = ft_memalloc(lenght + 1);
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		s[--lenght] = base[num % baze];
		num /= baze;
	}
	return (s);
}