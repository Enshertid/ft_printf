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
	if (**str == 'd' || **str == 'i')
		ft_signed_digital(str, list, va_arg(per, int));
	else if (**str == 'u')
		return (ft_unsigned_digital(str, list, va_arg(per, int)));
	else if (**str == 'o')
		return (ft_unsigned_octal(str, list, va_arg(per, int)));
	else if (**str == 'x')
		return (ft_unsigned_hex_low(str, list, va_arg(per, int)));
	else if (**str == 'X')
		return (ft_unsigned_hex_hight(str, list, va_arg(per, int)));
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