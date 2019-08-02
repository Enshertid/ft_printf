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

int			ft_digitals(const char **str, t_spec *list, va_list per)
{
	char			*numb;

	if (**str == 'd' || **str == 'i')
		numb = ft_flagsfor_signed(va_arg(per, int), list);
	if (**str == 'u')
		numb = ft_flagsfor_unsigned(va_arg(per, unsigned int), list, 10, 0);
	else if (**str == 'o')
		numb = ft_flagsfor_unsigned(va_arg(per, unsigned int), list, 8, 0);
	else if (**str == 'x')
		numb = ft_flagsfor_unsigned(va_arg(per, unsigned int), list, 16, 0);
	else if (**str == 'X')
		numb = ft_flagsfor_unsigned(va_arg(per, unsigned int), list, 16, 1);
	(*str)++;
	if (list->precision > list->width && list->precision > ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) > list->precision &&
								ft_strlen(numb) > list->width)
		return (ft_output_only_digital(numb));
	else if (list->width > list->precision)
		return (ft_start_pars_width(list, numb));
}

int					ft_type_definition(const char **str,
										  t_spec *list, va_list per)
{
	if (**str == 'd' || **str == 'i' || **str == 'u' || **str == 'o' ||
		**str == 'x' || **str == 'X')
		return (ft_digitals(str, list, per));
//		else if (**str == 'c')
//		return (ft_signed_char(str, list, per));
//	else if (**str == 's')
//		return (ft_string_output(str, list, per));
//	else if (**str == 'p')
//		return (ft_pointer_output(str, list, per));
//	else if (**str == 'f')
//		return (ft_signed_float(str, list, per));
	else
	{
		(*str)++;
		return (1);
	}
}