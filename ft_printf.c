/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/06 18:02:57 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_second_step(const char **str,
					va_list per, t_spec *list)
{
			ft_check_flags(str, list);
		ft_check_width(str, list, per);
		while (ft_isdigit(**str))
			(*str)++;
		ft_check_modificate(str, list);
		return (ft_type_definition(str, list, per));
}

int		ft_str_out(char *buf, char *str_out, int *i)
{
	int return_value;

		return_value = 0;
		write(1, buf, *i);
		ft_strclr(buf);
		write(1, str_out, ft_strlen(str_out));
		return_value += *i;
		*i = 0;
		return_value += ft_strlen(str_out);
		free(str_out);
		return (return_value);
}

int			ft_str_plusbuf(char *buf, char *str_out, int i)
{
	int j;

	{
		j = 0;
		while(str_out[j] && i < BUFF_SIZE)
		{
			buf[i] = str_out[j];
			i++;
			j++;
		}
		free(str_out);
	}
	return (j);
}

int			ft_cleanbuff_andout(char *buf, int i)
{

	write(1, buf, i);
	ft_strclr(buf);
	return (i);
}

int 		ft_first_step(const char *str, va_list per)
{
	char			buf[BUFF_SIZE];
	t_spec			*list;
	char			*str_out;
	int				return_value;
	int				i;

	i = 0;
	list = ft_list_new();
	return_value = 0;
	while (*str)
	{
		while (*str && *str != '%' && i < BUFF_SIZE + 1)
		{
			buf[i] = *str;
			i++;
			str++;
		}
		if (i == BUFF_SIZE)
		{
			return_value += ft_cleanbuff_andout(buf, BUFF_SIZE);
			i = 0;
		}
		if(*str)
		{
			str++;
			str_out = ft_second_step(&str, per, list);
			if (ft_strlen(str_out) + i >= BUFF_SIZE)
				return_value += ft_str_out(buf, str_out, &i);
			else
				i += ft_str_plusbuf(buf, str_out , i);
		}
		ft_list_clear(list);
	}
	return_value += ft_cleanbuff_andout(buf, i);
	free(list);
	return (return_value);
}

int 		ft_printf(const char *str, ...)
{
	va_list		per;
	int			return_value;

	va_start(per, str);
	return_value = ft_first_step(str, per);
	va_end(per);
	return (return_value);
}
