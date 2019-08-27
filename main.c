#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first primer:\n%U\n", LLONG_MAX);
	int b = printf("Pirst primer:\n%U\n", LLONG_MAX);
	printf("\nft_printf return value: %d\n2original return value: %d\n",a, b);
	int d = ft_printf("first primer:\n%#100x", 1234);
	int c = printf("Pirst primer:\n%#100x", 1234);
	printf("\nft_printf return value: %d\n2original return value: %d\n",d, c);
	return (0);
}