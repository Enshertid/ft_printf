#include "printf.h"

void	get_modifiers_and_type(const char **str, t_format *format)
{
	if (**str == 'h' && *(*str + 1) == 'h')
		format->modificate = CHAR;
	else if (**str == 'h')
		format->modificate = SHORT;
	else if (**str == 'l' && *(*str + 1) == 'l')
		format->modificate = LONG_LONG;
	else if (**str == 'l')
		format->modificate = LONG;
	else if (**str == 'L')
		format->modificate = LONG_DOUBLE;
	while (**str == 'h' || **str == 'l' || **str == 'L' || **str == 'j')
		++*str;
	format->type = **str;
	++*str;
}

void	get_flags(const char **str, t_format *format)
{
	while (**str == '-' || **str == '+' || **str == ' ' ||
			**str == '#' || **str == '\'' ||
			 (!format->flag_zero && **str == '0'))
	{
		if (**str == '-')
			format->flag_minus = 1;
		else if (**str == '+')
			format->flag_plus = 1;
		else if (**str == ' ')
			format->flag_space = 1;
		else if (**str == '#')
			format->flag_hash = 1;
		else if (**str == '0')
			format->flag_zero = 1;
		++*str;
	}
}

void	get_width_and_precision(const char **str,
				t_format *format, va_list argptr)
{
	int temp;

	format->width = ft_atoi(*str);
	if (**str == '*')
	{
		if ((temp = va_arg(argptr, int)) < 0)
			format->flag_minus = 1;
		format->width = ft_abs(temp);
	}
	while (**str == '*' || ft_isdigit(**str))
		++*str;
	format->dot_presence = **str == '.';
	*str += **str == '.';
	format->precision = ft_atoi(*str);
	if (**str == '*')
	{
		if ((temp = va_arg(argptr, int)) > 0)
			format->precision = temp;
	}
	while (**str == '*' || ft_isdigit(**str))
		++*str;
}

void	get_format(const char **str, t_format *format, va_list argptr)
{
	ft_memset(format, 0, sizeof(t_format));
	get_flags(str, format);
	get_width_and_precision(str, format, argptr);
	get_modifiers_and_type(str, format);
}
