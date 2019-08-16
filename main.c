#include "stdio.h"

#include "printf.h"
#include "wchar.h"
#include "limits.h"

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

	   printf("%+-10u|\n", 650);
	ft_printf("%+-10u|\n", 650);


	// long a = LLONG_MAX;
	// char *str_max = ft_mitoa(LLONG_MAX, 10, 0);
	// char *str_min = ft_mitoa(LLONG_MIN, 10, 0);
	// char *u_max = ft_mitoa(ULLONG_MAX, 10, 0);

	// printf("%s\n", str_max);
	// printf("%s\n", str_min);
	// printf("%s\n", u_max);

	// int a;
	// int b;

	// a = ft_printf("%#23.X|\n%023.X|\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	// printf("------------------------------\n");
	// b =    printf("%#23.X|\n%023.X|\n\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	// printf("\na = %i, b = %i\n\n\n", a, b);

	// a = ft_printf("%23.X|\n%-23.X|\n%#23.X|\n%023.X\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	// printf("------------------------------\n");
	// b =    printf("%23.X|\n%-23.X|\n%#23.X|\n%023.X\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	// printf("\na = %i, b = %i\n\n\n", a, b);

	// a = ft_printf("%#23.5hX|\n%023.5hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	// printf("------------------------------\n");
	// b =    printf("%#23.5hX|\n%023.5hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	// printf("\na = %i, b = %i\n\n\n", a, b);

	// a = ft_printf("%23.5hX|\n%-23.5hX|\n%#23.5hX|\n%023.5hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	// printf("------------------------------\n");
	// b =    printf("%23.5hX|\n%-23.5hX|\n%#23.5hX|\n%023.5hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	// printf("\na = %i, b = %i\n\n\n", a, b);

//	ft_printf("%f\n", 123456.876543);


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



