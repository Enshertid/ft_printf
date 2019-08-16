#include "stdio.h"

#include "printf.h"
#include "wchar.h"

#include "math.h"
#include "float.h"

int			main(void)
{		//			 9223372036854775809
// 	printf("%lu\n", 9223372036854775809);
// 	unsigned long long a;
// 	memset(&a, 9, sizeof(unsigned long long));
// 	printf("%llu\n", a);
// 	// a <<= 1;
// 	// a >>= 1;
// 	printf("%llu\n", a);

	// int a[40];
	// for (int i = 0; i < 40; ++i)
	// 	a[i] = i;

	//    printf("%0.20p|\n", 1234);
	// ft_printf("%+20.p|\n", 1234);

	   printf("%f\n", DBL_MAX);
	ft_printf("%f\n", DBL_MAX);


	// for (unsigned char i = 128; i < 200; ++i)
	// {
	// 	ft_putchar(i);
	// 	ft_putchar('|');
	// }

	

	// printf("%zu\n%zu\n%zu\n", sizeof(double), sizeof(double_t), sizeof(long double));

	// int a =    printf("|qwerty%#22.15ozxc|\n", 1854);
	// int b = ft_printf("|qwerty%#22.15ozxc|\n", 1854);		// error!!!

	// printf("a: %i, b: %i\n", a , b);

	return (0);
}



