
#include "printf.h"

int			main(void)
{
	printf("%s\n\n\n|%+-10.*i|\n\n", "% 15.6i", 5, 154);
	ft_printf("%+-10.*i", 5, 154);
	// printf("%s\n\n\n|%- 6.12i|\n\n", "% 15.6i", -154);
	// ft_printf(      "%- 6.12i", -154);

	return (0);
}