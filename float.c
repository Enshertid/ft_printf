#include "printf.h"

void print_double(double d)
{
	long long a;

	if (d && d == d * 10)
			printf("inf\n");
	else if (d != d)
		printf("nan\n");
	else
	{
		a = (int)d;
		printf("%lli|\n", a);
	}
}

void print_long_double(long double d)
{
	long long a;
	
	if (d && d == d * 10)
		printf("inf\n");
	else if (d != d)
		printf("nan\n");
	else
	{
		a = (int)d;
		printf("%lli|\n", a);
	}
}

void print_float(t_format *format, va_list argptr)
{
	if (format->modificate == 'l')
		print_double(va_arg(argptr, long double));
	else
		print_long_double(va_arg(argptr, double));

	
}