/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/12 18:45:28 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_second_step(const char **str,
					va_list per, t_spec *list, t_buff *buff)
{
	ft_check_flags(str, list);
	ft_check_width(str, list, per);
	while (ft_isdigit(**str))
		(*str)++;
	ft_check_modificate(str, list);
	return (ft_type_definition(str, list, per, buff));
}

void		ft_str_out(char *str_out, t_buff *buff)
{
	int j;
	char *temp = str_out;

	j = 0;
	if (ft_strlen(str_out) + buff->i > BUFF_SIZE)
	{
		write(1, buff->buff, buff->i);
		write(1, str_out, ft_strlen(str_out));
		j += buff->i;
		j += ft_strlen(str_out);
		ft_cleaning_buf(buff);
		buff->return_value += j;
		free(temp);
	}
	else
	{
		while(str_out[j] && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str_out[j++];
		free(temp);
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

	while (*str && buff->i < BUFF_SIZE + 1)
	{
		if(*str != '%' && buff->i != BUFF_SIZE)
			buff->buff[buff->i++] = *str++;
		if (buff->i == BUFF_SIZE)
			ft_cleanbuff_andout(list, buff);
		if(*str == '%')
		{
			str++;
			if (*str)
			{
				ft_str_out(ft_second_step(&str, per, list, buff), buff);
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
