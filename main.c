#include "float.h"
#include "math.h"
#include "ft_printf.h"

int			main(void)
{
	long double d = 44.5 + 1e-52;
	int a =    printf("%.f|%.f|%.f|%.f|%.Lf|\n", 44.5, 44.4, 44.6, 44.50001, d);
	int b = ft_printf("%.f|%.f|%.f|%.f|%.Lf|\n", 44.5, 44.4, 44.6, 44.50001, d);





	// ft_printf("%f\n", d1);
	// printn_bits(&d2, 8);
	// printn_bits(&d3, 8);

	printf("%i - %i\n", a, b);

	return (0);
}

// 2147483647
// 2147481999