/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:59:11 by dbendu            #+#    #+#             */
/*   Updated: 2019/09/13 10:01:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*set_width(char *str, char *iter, t_spec *list, size_t double_len)
// {
// 	char		*new_str;
// 	size_t		pos;

// 	new_str = ft_strnew(list->width);
// 	pos = 0;
// 	if (!ft_isdigit(*iter))
// 	{
// 		new_str[pos++] = *iter++;
// 		--double_len;
// 	}
// 	if (list->flag_zero || !list->flag_minus)
// 	{
// 		ft_memset(new_str + pos, list->flag_zero ? '0' : ' ',
// 					list->width - double_len);
// 		pos += list->width - double_len;
// 	}
// 	ft_memcpy(new_str + pos, iter, double_len);
// 	pos += double_len;
// 	if (list->flag_minus)
// 	{
// 		ft_memset(new_str + pos, ' ', list->width - double_len);
// 		pos += list->width - double_len;
// 	}
// 	free(str);
// 	return (new_str);
// }

char	*set_width(char *str, char *iter, t_spec *list, size_t double_len)
{
	char	*new_str;
	size_t	pos;

	new_str = (char*)malloc(list->width + 1);
	list->width -= double_len;
	pos = 0;
	if (!list->flag_minus && list->flag_zero && !ft_isdigit(*iter))
		new_str[pos++] = *(iter++);
	if (!list->flag_minus)
	{
		ft_memset(new_str + pos, list->flag_zero ? '0' : ' ', list->width);
		pos += list->width;
	}
	if (!list->flag_minus && !list->flag_zero && !ft_isdigit(*iter))
		new_str[pos++] = *(iter++);
	ft_memcpy(new_str + pos, iter, double_len);
	pos += double_len;
	if (list->flag_minus)
	{
		ft_memset(new_str + pos, ' ', list->width);
		pos += list->width;
	}
	new_str[pos] = '\0';
	free(str);
	return (new_str);
}

char *get_double(const char **str, va_list pre, t_spec *list)
{
	char		*str_out;
	char		*iter;
	char		*iter1;
	size_t		double_len;

	(*str)++;
	if (list->mod == LONG_DOUBLE)
		str_out = double_to_str(va_arg(pre, long double), list);
	else
		str_out = double_to_str(va_arg(pre, double), list);
	iter = ft_memnchr(str_out, 0, 3);
	double_len = ft_strlen(iter);
	if (list->width > double_len)
		return (set_width(str_out, iter, list, double_len));
	iter1 = str_out;
	while (*(iter))
		*(iter1++) = *(iter++);
	*iter1 = *iter;
	return (str_out);
}