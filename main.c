#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first primer:\n%-#.5hX|%-0.5hX|%#0.5hX|%-#0.5hX", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	int b = printf("Pirst primer:\n%-#.5hX|%-0.5hX|%#0.5hX|%-#0.5hX", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	printf("\nft_printf return value: %d\n2original return value: %d\n",a, b);
//	int d = ft_printf("first primer:\n");
//	int c = printf("Pirst primer:\n");
//	printf("\nft_printf return value: %d\n2original return value: %d\n",d, c);
	return (0);
}
