
#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first_primer:%# 0109.21dd\nsecondblabla\n", -34100);
	int b = printf("first_primer:%# 0109.21dd\nsecondblabla\n", -34100);
	printf("original_return_value = %d\n ft_pritnf_return_value = %d\n", b , a);
	return (0);
}