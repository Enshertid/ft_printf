//
// Created by Yaxley Manilow on 2019-07-31.
//
#include "ft_printf.h"

int					ft_width_noprecision(char *numb, t_spec *list, char *str, char *str_head)
{
	char				*numb_head;
	int					return_value;

	numb_head = numb;
	if ((numb[0] == '+' || numb[0] == '-' || numb[0] == ' ') && list->presence_dot == 0)
	{
		str[0] = numb[0];
		numb++;
		str++;
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

int					ft_width_with_precision(char *numb, t_spec *list, char *str , char *str_head)
{
	char				*numb_head;
	int					return_value;
	int					start_of_numb;
	int					iter;

	numb_head = numb;
	iter = (ft_strlen(str) - list->precision - 1);
	if (numb[0] == '+' || numb[0] == '-' || numb[0] == ' ')
	{
		str[iter] = numb[0];
		numb++;
		iter++;
	}
	start_of_numb = ft_strlen(str) - ft_strlen(numb);
	while (iter != start_of_numb)
	{
		str[iter] = '0';
		iter++;
	}
	while (str[iter] && *numb)
	{
		str[iter] = *numb;
		iter++;
		numb++;
	}
	free(numb_head);
	return_value = ft_strlen(str_head);
	write(1,str_head,return_value);
	free(str_head);
	return (return_value);
}

int					ft_right_aligned_without_precision(char *numb, char *str, char *str_head)
{
	char				*numb_head;
	int					return_value;

	numb_head = numb;
	if (numb[0] == '+' || numb[0] == '-' || numb[0] == ' ')
	{
		str[0] = numb[0];
		numb++;
		str++;
	}
	while (*numb && *str)
	{
		*str = *numb;
		str++;
		numb++;
	}
	return_value = ft_strlen(str_head);
	write(1, str_head, return_value);
	free(str_head);
	free(numb_head);
	return (return_value);
}

int					ft_right_aligned_with_precision(char *numb, char *str, t_spec *list, char *str_head)
{
	char				*numb_head;
	int					return_value;
	int					iter;
	int					start_of_numb;

	numb_head = numb;
	if (numb[0] == '+' || numb[0] == '-' || numb[0] == ' ')
	{
		str[0] = numb[0];
		numb++;
		str++;
	}
	iter = 0;
	start_of_numb = list->precision - ft_strlen(numb);
	while (iter != start_of_numb)
	{
		str[iter] = '0';
		iter++;
	}
	while (str[iter] && *numb)
	{
		str[iter] = *numb;
		iter++;
		numb++;
	}
	free(numb_head);
	return_value = ft_strlen(str_head);
	write(1,str_head,return_value);
	free(str_head);
	return (return_value);
}

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