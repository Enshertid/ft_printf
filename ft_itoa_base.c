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

char		*ft_itoa_hex(long long int num, unsigned size)
{
	char						*s;
	char						*base;
	unsigned					n;
	unsigned					lenght;

	lenght =ft_checklenght(num, 16);
	base = (size == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (!(s = (char*)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	s[lenght] = '\0';
	n = num;
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[--lenght] = base[n % 16];
		n /= 16;
	}
	return (s);
}

char		*ft_itoa_oct(long long int num)
{
	char					*s;
	char					*base;
	unsigned				n;
	unsigned				lenght;

	lenght =  ft_checklenght(num, 8);
	base = "01234567";
	if (!(s = (char*)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	s[lenght] = '\0';
	n = num;
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[--lenght] = base[n % 8];
		n /= 8;
	}
	return (s);
}

char		*ft_itoa_base(long long int num, unsigned system, unsigned size)
{
	if (system == 16)
		return (ft_itoa_hex(num, size));
	else if (system == 10)
		return (ft_itoa(num));
	else if (system == 8)
		return (ft_itoa_oct(num));
	else
		return (NULL);
}