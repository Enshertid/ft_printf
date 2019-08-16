#include "libft.h"

long double	ft_pow(long double a, int n)
{
	long double even;

	if (!n)
		return (1);
	else if (n < 0)
		return (1 / ft_pow(a, -n));
	else if (!(n & 1))
	{
		even = ft_pow(a, n / 2);
		return (even * even);
	}
	else
		return (a * ft_pow(a, n - 1));
}