//
// Created by Yaxley Manilow on 30/08/2019.
//

#include "ft_printf.h"

char				*ft_before_dot(double per, t_spec *list)
{
	char *str;
	char *str_out;

	str = ft_strnew(6);
	str_out = str;
	*str++ = '1';
	*str++ = '4';
	ft_memset(str, '0', 4);
	return (str_out);
}

char				*ft_after_dot(double numb, t_spec *list)
{
	char *str;
	char *str_out;

	str = ft_strnew(2);
	str_out = str;
	*str++ = '3';
	*str = '.';
	return (str_out);
}

char				*ft_float_width(char *before, char *after, t_spec *list, int ln)
{
	size_t			i;
	size_t			j;
	char		*str_out;

	i = 0;
	j = 0;
	str_out = ft_strnew(list->width);
	if (list->flag_zero == 1 && list->flag_minus == 0)
		ft_memset(str_out, '0', list->width);
	else
		ft_memset(str_out, ' ', list->width);
	if (list->flag_minus == 1)
		i += list->width - ln;
	while (str_out[i])
	{
		while(before[j] && str_out[i])
			str_out[i++] = before[j++];
		j = 0;
		while (after[j] && str_out[i])
			str_out[i++] = before[j++];
	}
	return (str_out);
}

char				*ft_float(char **str, double numb, t_spec *list)
{
	char		*str_out;
	char		*after_dot;
	char		*before_dot;
	int			ln;

	(*str)++;
	before_dot = ft_before_dot(numb, list);
	after_dot = ft_after_dot(numb, list);
	ln = ft_strlen(after_dot)+ ft_strlen(before_dot);
	if (list->width > ln)
		str_out = ft_float_width(before_dot, after_dot, list, ln);
	else
		str_out = ft_strjoin(after_dot, before_dot);
	free(before_dot);
	free(after_dot);
	return(str_out);
}