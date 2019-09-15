#include "math.h"
#include "float.h"

#include "ft_printf.h"

int			main(void)
{
	long double	d;
	char		*str;
	t_spec		format;
	int			prec;


	prec = DBL_SIZE;

	// d = ft_dpow(2, -16381);
	d = LDBL_MIN;

	str = double_to_str(d, &format);

	printf("%.*Lf\n", prec, d);


	for (int i = 2; i < prec; ++i)
	{/* code */
		if (str[i])
			write(1, str + i, 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);

	// for (int i = 1; i < 20; ++i)
	// 	printf("%d\n", 970 * i);

	

	// int ret1 =    printf("%.16500Lf\n", d);
	// int ret2 = ft_printf("%Lf\n", d);
	// printf("\n%i -- %i\n", ret1, ret2);


	return (0);
}
