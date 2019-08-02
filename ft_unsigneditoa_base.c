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

char		*ft_unsigned_itoa_base(unsigned int num,int base , unsigned size)
{
	char						*s;
	char						*base_ar;
	unsigned					lenght;

	lenght =ft_checklenght(num, base);
	if (base == 16)
		base_ar = (size == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	else if (base == 8)
		base_ar = "01234567";
	else if (base == 10)
		base_ar = "0123456789";
	else
		return ("check base");
	s = ft_memalloc(lenght + 1);
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		s[--lenght] = base_ar[num % base];
		num /= base;
	}
	return (s);
}