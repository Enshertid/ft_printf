#include "ft_printf.h"

int			main(void)
{
	// long double d = 9.99;
	//    printf("|%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f|\n", 0., 0., 0., 0., 0., 0.);
	 ft_printf("|%23li|%-23li|%+23li|% 23li|%023li\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
	 printf ("|%23li|%-23li|%+23li|% 23li|%023li", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);


	long double d = 244.11;

	/*{
		"\e[38;5;001m", "\e[38;5;002m", "\e[38;5;003m",
				"\e[38;5;004m", "\e[38;5;005m", "\e[38;5;006m",
				"\e[38;5;011m", "\e[38;5;013m", "\e[38;5;014m",
				"\e[38;5;042m", "\e[38;5;046m", "\e[38;5;082m",
				"\e[38;5;225m"
	};*/

//	printf ("\e[38;5;");
//	printf ("003m");
//	printf ("hello\n");
//	printf ("\e[38;5;225m");

	printf("\n");
	printf ("\e[38;5;");
	printf ("004m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("005m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("006m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("007m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("008m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("009m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("010m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("011m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("012m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("013m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	printf ("\e[38;5;");
	printf ("232m");
	printf ("hello\n");
	printf ("\e[38;5;225m");

	return (0);
}
