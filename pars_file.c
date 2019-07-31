//
// Created by Yaxley Manilow on 2019-07-31.
//
#include "ft_printf.h"
char				*ft_pars_num(int num, t_spec *list)
{
	char				*numb;

	if(list->flag_plus == 1 && list->flag_space == 1)
		return ("warning");
	if (num > 0 && list->flag_plus == 1)
	{
		numb = ft_itoa(-num);
		numb[0] = '+';
	}
	else if (num > 0 && list->flag_space == 1)
	{
		numb = ft_itoa(-num);
		numb[0] = ' ';
	}
	else if (num < 0 || num > 0)
		numb = ft_itoa(num);
	return (numb);
}