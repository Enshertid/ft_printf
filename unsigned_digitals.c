//
// Created by Yaxley Manilow on 2019-08-01.
//

#include "ft_printf.h"

int				ft_unsigned_digital(const char **str, t_spec *list, unsigned int num)
{
	char			*numb;

	(*str)++;
	numb = ft_unsigned_itoa_base(num, 10, 0);
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
			 ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return (ft_start_pars_width(list, numb));
}

int				ft_unsigned_octal(const char **str, t_spec *list, unsigned int num)
{
	char			*numb;

	(*str)++;
	numb = ft_unsigned_itoa_base(num, 8, 0);
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
			 ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return (ft_start_pars_width(list, numb));
}

int				ft_unsigned_hex_low(const char **str, t_spec *list, int num)
{
	char			*numb;

	(*str)++;
	printf (" CHISLO =====>%d\n", num);
	numb = ft_unsigned_itoa_base(num, 16, 0);
	printf ("STROKA =====> %s\n", numb);
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
			 ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return (ft_start_pars_width(list, numb));
}

int				ft_unsigned_hex_hight(const char **str, t_spec *list, int num)
{
	char			*numb;

	(*str)++;
	numb = ft_unsigned_itoa_base(num, 16, 1);
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
			 ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return (ft_start_pars_width(list, numb));
}
