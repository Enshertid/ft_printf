/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:14:35 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/05 14:32:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mitoa(long long int num, unsigned base, unsigned size)
{
	const char	*alphabet = size ? "0123456789ABCDEF" : "0123456789abcdef";
	char		*result;
	size_t		pos;

	if (num == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (base < 2 || base > 16 ||
		!(result = ft_strnew(sizeof_num(num, base))))
		return (NULL);
	if (base == 10 && num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	result[0] = '0';
	pos = (base == 10 && num < 0);
	while (num)
	{
		result[pos++] = alphabet[num % base];
		num /= base;
	}
	ft_strrev(result + (result[0] == '-'));
	return (result);
}