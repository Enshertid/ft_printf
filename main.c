#include "ft_printf.h"

int			main(void)
{
	// long double d = 9.99;
	//    printf("|%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f|\n", 0., 0., 0., 0., 0., 0.);
	// ft_printf("|%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f|\n", 0., 0., 0., 0., 0., 0.);

	long double d = 0;

	   printf("|%+12.Lf|\n", d);
	ft_printf("|%+12.Lf|\n", d);

	return (0);
}
