//
// Created by Yaxley Manilow on 2019-08-25.
//

#include "ft_printf.h"

char				*ft_pointer_output(const char **str, t_spec *list, ptrdiff_t per)
{
	char *numb;

	list->mod = DEFAULT;
	list->flag_hash = 1;
	if (per == 0)
		numb = ft_strdup("0x0");
	else
		numb = ft_flag_unsign(per, list, **str);
	(*str)++;
	if (list->precision >= list->width &&
		list->precision + list->flag_us >= ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) - list->flag_us > list->precision &&
			 ft_strlen(numb) > list->width)
		return (numb);
	else if (list->width > list->precision)
		return (ft_parswidth(list, numb));
	else
		return (numb);
}