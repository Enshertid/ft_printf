
#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first_primer:%--  ++---15.10dd\nsecondblabla\n", 525);
	int b = printf("first_primer:%--- ++-15.10dd\nsecondblabla\n", 525);
	printf("original_return_value = %d\n ft_pritnf_return_value = %d\n", b , a);


	return (0);
}