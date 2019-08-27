/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:00:55 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/23 13:00:56 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec		*ft_list_new()
{
	t_spec	*list;

	if (!(list = malloc(sizeof(t_spec))))
		return (NULL);
	list->flag_minus = 0;
	list->flag_plus = 0;
	list->flag_zero = 0;
	list->flag_hash = 0;
	list->flag_space = 0;
	list->width = 0;
	list->presence_dot = 0;
	list->precision = 0;
	list->mod = DEFAULT;
	list->flag_us = 0;
	list->flag_o = 0;
	return (list);
}

void		ft_list_clear(t_spec *list)
{
	list->flag_minus = 0;
	list->flag_plus = 0;
	list->flag_zero = 0;
	list->flag_hash = 0;
	list->flag_space = 0;
	list->width = 0;
	list->precision = 0;
	list->presence_dot = 0;
	list->flag_us = 0;
	list->flag_o = 0;
	list->mod= DEFAULT;
}

void		ft_cleaningflags_char(t_spec *list)
{
	list->flag_o = 0;
	list->flag_us = 0;
	list->flag_space = 0;
	list->flag_hash = 0;
	list->flag_space = 0;
	list->mod= DEFAULT;
}

t_buff		*ft_buf_new()
{
	t_buff	*buf;
	int		i;

	i = 0;
	if(!(buf = malloc(sizeof(t_buff))))
		return (NULL);
	while (i < BUFF_SIZE)
		buf->buff[i++] = '0';
	buf->return_value = 0;
	buf->i = 0;
	return (buf);
}

void		ft_cleaning_buf(t_buff *buff)
{
	int i;

	i = 0;
	buff->i = 0;
	ft_strclr(buff->buff);
}