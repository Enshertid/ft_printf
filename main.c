#include "float.h"
#include "math.h"
#include "ft_printf.h"
#include <fcntl.h>

int			main(void)
{
	long double d = 44.5 + 1e-52;
	int fd = open("/Users/ymanilow/curcus42/ft_printf/file.txt", O_RDWR);
	int a =    printf("%100.1d\n", 9554532);
	int b = ft_printf("%10.4b\n%0100d\n",555, fd, 9554532);
	printf("%100.1d\n", 9554532);




	// ft_printf("%f\n", d1);
	// printn_bits(&d2, 8);
	// printn_bits(&d3, 8);

//	printf("%i - %i\n", a, b);

	return (0);
}

// 2147483647
// 2147481999