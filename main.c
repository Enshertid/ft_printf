#include "float.h"
#include "math.h"
#include "ft_printf.h"

int			main(void)
{
	long double d = LDBL_MIN;

	int a =    printf("%-.Lf\n", d);
	int b = ft_printf("%-2000000.200100Lf\n", d);

	printf("%i - %i\n", a, b);

	return (0);
}

// 2147483647
// 2147481999