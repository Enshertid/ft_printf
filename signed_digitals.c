//
// Created by Yaxley Manilow on 2019-08-01.
//

#include "ft_printf.h"

int					ft_output_only_precision(char *numb, t_spec *list)
{
	char				*str;
	char				*str_head;
	char				*numb_head;
	int					return_value;

	str = ft_strnew(list->precision + 2);
	ft_memset(str,'0', list->precision + 1);
	str_head = str;
	numb_head = numb;
	if (numb[0] == '+' || numb[0] == '-' || numb[0] == ' ')
	{
		str[0] = numb[0];
		str++;
		numb++;
	}
	str += (ft_strlen(str) - ft_strlen(numb));
	while (*str && *numb)
	{
		*str = *numb;
		str++;
		numb++;
	}
	free(numb_head);
	return_value = ft_strlen(str_head);
	write(1,str_head,return_value);
	free(str_head);
	return (return_value);
}

int					ft_output_only_digital(char *numb)
{
	int		return_value;

	return_value = ft_strlen(numb);
	write(1, numb, return_value);
	free(numb);
	return (return_value);
}

char				*ft_flagsfor_signed(int num, t_spec *list)
{
	char				*numb;

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
	else //(num < 0 || num > 0)
		numb = ft_itoa(num);
	return (numb);
}

int			ft_signed_digital(const char **str, t_spec *list, int num)
{
	char			*numb;

	(*str)++;
	numb = ft_flagsfor_signed(num, list);
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
			 ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return(ft_start_pars_width(list, numb));
}