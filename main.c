#include "math.h"
#include "float.h"

#include "ft_printf.h"

int			main(void)
{
	long double	d;
	char		*str;
	t_spec		format;
	int			prec;
	// long double d = 9.99;
	//    printf("|%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f|\n", 0., 0., 0., 0., 0., 0.);
//	 int fd = open("/Users/ymanilow/curcus42/ft_printfall/file.txt", O_RDWR);
	//  ft_printf("|%23li|%-23li|%+23li|% 23li|%023li\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX,
	//  		LLONG_MAX);
	//  printf ("|%23li|%-23li|%+23li|% 23li|%023li", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);


//	long double d = 244.11;

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


	prec = DBL_SIZE;

	// d = ft_dpow(2, -16381);
	d = LDBL_MIN;

	str = double_to_str(d, &format);

	printf("%.*Lf\n", prec, d);


	for (int i = 2; i < prec; ++i)
	{/* code */
		if (str[i])
			write(1, str + i, 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);

	// for (int i = 1; i < 20; ++i)
	// 	printf("%d\n", 970 * i);

	

	// int ret1 =    printf("%.16500Lf\n", d);
	// int ret2 = ft_printf("%Lf\n", d);
	// printf("\n%i -- %i\n", ret1, ret2);


	return (0);
}
