#include "float.h"
#include "math.h"
#include "ft_printf.h"

int			main(void)
{

	int a =    printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f|\n", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY);
	int b = ft_printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f|\n", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY);

	printf("%i - %i\n", a, b);

	return (0);
}

// 2147483647
// 2147481999