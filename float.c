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
		float s = d - (float)a;
		printf("%lli|\n%f\n", a, s);
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
	if (format->modificate == LONG_DOUBLE)
		print_long_double(va_arg(argptr, long double));
	else
		print_double(va_arg(argptr, double));

	
}