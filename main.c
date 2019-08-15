#include "ft_printf.h"

int			main(void)
{
	int a = ft_printf("first_primer:\n%X|\n%-X|\n%#X|\n%0X\n", 0U, 0U, 0U, 0U);
	int b = printf("Pirst_primer:\n%X|\n%-X|\n%#X|\n%0X\n", 0U, 0U, 0U, 0U);
//	int c = ft_printf("second_primer:\n%23ld|\n%-23ld|\n%+23ld|\n% 23ld|\n%023ld\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
//	int d = printf("pecond_primer:\n%23ld|\n%-23ld|\n%+23ld|\n% 23ld|\n%023ld\n", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
	printf("2original_return_value = %d\nft_pritnf_return_value = %d\n", b, a );
//	printf("2original_return_value = %d\nft_pritnf_rкeturn_value = %d\n", d, c );
	return (0);
}
