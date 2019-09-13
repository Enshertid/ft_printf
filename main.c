#include "ft_printf.h"
#include "math.h"

int			main(void)
{
//	printf("%20.120f\n", 9.99);
//	printf ("%20.120d\n", 999);
	int b = ft_printf("first primer:%-+f % 11f\n", 9.999, 9.999);
//	int d = printf("Pirst primer%f%11f\n",-3.167, 3.167);
//	printf("\nft_printf return value: %d\n2original return value: %d\n",b, d);
//	printf("\nft_printf return value: %d\n2original return value: %d\n",a, c);
	return (0);
}
