
#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first_primer:%#15.0ud\nsecondblabla\n", -100);
	int b = printf("first_primer:%#15.0ud\nsecondblabla\n", -100);
	printf("original_return_value = %d\n ft_pritnf_return_value = %d\n", b , a);

		char *s;
		s = ft_unsigned_itoa_base(-4294967295, 16, 1);
		printf("stroka = %s\n", s);
		return (0);

	return (0);
}