
#include "printf.h"

int			main(void)
{			//		 9223372036854775809
	printf("%lu\n", 9223372036854775809);
	// unsigned long long a;
	// memset(&a, 9, sizeof(unsigned long long));
	// printf("%llu\n", a);
	// // a <<= 1;
	// // a >>= 1;
	// printf("%llu\n", a);

	//    printf("|qwerty%19.10luzxc|\n", -9223372036854775807);
	// ft_printf("|qwerty%19.10luzxc|\n", -9223372036854775807);


//	   printf("|qwerty%#22.15ozxc|\n", 1854);
//	ft_printf("|qwerty%#22.15ozxc|\n", 1854);		// error!!!
	

	return (0);
}