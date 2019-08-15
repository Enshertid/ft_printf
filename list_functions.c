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
	list->flag_hashus = 0;
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
	list->flag_hashus = 0;
	list->mod= DEFAULT;
}