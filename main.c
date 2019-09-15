#include "float.h"
#include "math.h"
#include "ft_printf.h"

int			main(void)
{
	long double d = DBL_MAX;
	int prec = 100;

	int a =    printf("%+ .*Lf\n", prec, d);
	int b = ft_printf("%+ .*Lf\n", prec, d);

	printf("%i - %i\n", a, b);

	return (0);
}
