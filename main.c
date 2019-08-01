
#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first_primer:%0-+15.0dd\nsecondblabla\n", 525);
	int b = printf("first_primer:%0+-15.0od\nsecondblabla\n", -500);
	printf("original_return_value = %d\n ft_pritnf_return_value = %d\n", b , a);

		char *s;
		s = ft_itoa_base(-500, 8, 0);
		printf("stroka = %s\n", s);
		return (0);

	return (0);
}