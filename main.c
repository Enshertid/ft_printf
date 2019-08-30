#include "ft_printf.h"

int			main(void)
{
	int d = ft_printf("first primer:\n%f\n", 3.14);
	int c = printf("Pirst primer:\n%f\n", 3.14);
	printf("\nft_printf return value: %d\n2original return value: %d\n",d, c);
	return (0);
}
