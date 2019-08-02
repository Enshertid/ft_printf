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
	if (numb[0] == '0' && (numb[1] == 'x' || numb[1] == 'X'))
	{
		str[0] = numb[0];
		str[1] = numb[1];
		str += 2;
		numb += 2;
	}
	else if (numb[0] == '+' || numb[0] == '-' || numb[0] == ' ' || numb[0] == '0')
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