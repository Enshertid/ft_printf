/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_the_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:10:54 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/30 19:10:55 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_pars_num(int num, t_spec *list)
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


int					ft_start_pars_width(t_spec *list, char *numb)
{
	char				*str_head;
	char				*str;

	str = ft_strnew(list->width);
	if (list->presence_dot == 0 && list->flag_zero == 1 && list->flag_minus == 0)
		ft_memset(str, '0', list->width);
	else
		ft_memset(str, ' ', list->width);
	str_head = str;
	if (ft_strlen(numb) > list->precision && list->flag_minus == 0)
		return (ft_width_noprecision(numb, list, str, str_head));
	else if (ft_strlen(numb) < list->precision && list->flag_minus == 0)
		return (ft_width_with_precision(numb, list, str, str_head));
	else if (list->flag_minus == 1 && ft_strlen(numb) > list->precision)
		return (ft_right_aligned_without_precision(numb, str, str_head));
	else if (list->flag_minus == 1 && ft_strlen(numb) < list->precision)
		return (ft_right_aligned_with_precision(numb, str, list, str_head));
}

int			ft_signed_digital(const char **str, t_spec *list, int num)
{
	char			*numb;

	(*str)++;
	numb = ft_pars_num(num, list);
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
	ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return(ft_start_pars_width(list, numb));
}