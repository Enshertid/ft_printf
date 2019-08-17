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

void		ft_str_out(char *str_out, t_buff *buff)
{
	int j;

	j = 0;
	if (ft_strlen(str_out) + buff->i > BUFF_SIZE)
	{
		write(1, buff->buff, buff->i);
//		ft_strclr(buff->buff);
		write(1, str_out, ft_strlen(str_out));
		j += buff->i;
		j += ft_strlen(str_out);
		ft_cleaning_buf(buff);
		buff->return_value += j;
		free(str_out);
	}
	else
	{
		while(str_out[j] && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str_out[j++];
		free(str_out);
	}
}

void		ft_cleanbuff_andout(t_spec *list, t_buff *buff)
{

	buff->return_value += buff->i;
	write(1, buff->buff, buff->i);
	if (buff->i == BUFF_SIZE)
		buff->i = 0;
	ft_cleaning_buf(buff);
	ft_list_clear(list);
}

void			ft_real_second_step(t_buff *buff, t_spec *list, const char *str, va_list per)
{
	char *str_out;

	while (*str && buff->i < BUFF_SIZE + 1)
	{
		if(*str != '%' && buff->i != BUFF_SIZE)
			buff->buff[buff->i++] = *str++;
		if (buff->i == BUFF_SIZE)
			ft_cleanbuff_andout(list, buff);
		if(*str == '%')
		{
			str++;
			if (*str == '%')
				buff->buff[buff->i++] = *str++;
			else if (*str)
			{
				str_out = ft_second_step(&str, per, list);
				ft_str_out(str_out, buff);
				ft_list_clear(list);
			}
		}
	}
}


int			ft_first_step(const char *str, va_list per)
{
	t_buff			*buff;
	t_spec			*list;
	int				return_value;

	list = ft_list_new();
	buff = ft_buf_new();
	ft_real_second_step(buff, list, str, per);
	ft_cleanbuff_andout(list, buff);
	free(list);
	return_value = buff->return_value;
	free(buff);
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
