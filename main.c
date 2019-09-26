#include "ft_printf.h"

#include "time.h"

int	main(void)
{
	// long double d = 11.576;

	// for (int i = 0; i < 13; ++i)
	// 	d /= 10;

	// *((char*)&d) &= 255;
	// printn_bits(&d, 10);

	long double d;

	for (int i = 196; i < 257; ++i)
	{
		d = ft_dpow(2, -i);

		printf("%i:\n", i);
		printf("%.120Lf\n", d);
		ft_printf("%.120Lf\n", d);

		printf("\n\n");
	}

	return (0);
}
