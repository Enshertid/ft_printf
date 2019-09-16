#include "float.h"
#include "math.h"
#include "ft_printf.h"

char	*get_binary(void *ptr, t_spec *format)
{
	char	*str;
	size_t size;

	str = (char*)malloc(format->)
}
	void	print_bits(void *a, size_t size)
{
	char	buf[size * 8 + size];
	size_t	pos;
	int		byte;
	int		offset;

	pos = 0;
	byte = size;
	while (--byte >= 0)
	{
		offset = 8;
		while (--offset >= 0)
			buf[pos++] = '0' + ((*((char*)a + byte) >> offset) & 1);
		buf[pos++] = ' ';
	}
	write(1, buf, size * 8 + size);
}

int			main(void)
{
	long double d = 44.5 + 1e-52;
	int a =    printf("%.f|%.f|%.f|%.f|%.Lf|\n", 44.5, 44.4, 44.6, 44.50001, d);
	int b = ft_printf("%.f|%.f|%.f|%.f|%.Lf|\n", 44.5, 44.4, 44.6, 44.50001, d);





	// ft_printf("%f\n", d1);
	// printn_bits(&d2, 8);
	// printn_bits(&d3, 8);

	printf("%i - %i\n", a, b);

	return (0);
}

// 2147483647
// 2147481999