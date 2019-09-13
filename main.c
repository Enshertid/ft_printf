#include "ft_printf.h"

int			main(void)
{
	// long double d = 9.99;
	//    printf("|%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f|\n", 0., 0., 0., 0., 0., 0.);
	// ft_printf("|%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f|\n", 0., 0., 0., 0., 0., 0.);

	// long double d = 0;

	// int a =    printf("%.1150f|%.1150f|%.1150f|%.1150f|\n", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
	// int b = ft_printf("%.1150f|%.1150f|%.1150f|%.1150f|\n", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);

	// long double d = 0x1.59a8b0c3dp-1037;
	int a =    printf("%.f|%.f|%.f|%.f|%.f|\n", 44.5, 44.5000001, 44.6, 44.50001, 44.5 + 1e-52);
	int b = ft_printf("%.f|%.f|%.f|%.f|%.f|\n", 44.5, 44.5000001, 44.6, 44.50001, 44.5 + 1e-52);
	printf("%i - %i\n", a, b);

	return (0);
}
