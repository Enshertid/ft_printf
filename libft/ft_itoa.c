/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:14:35 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/01 23:12:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num, unsigned base)
{
	const char alphabet[16] =
	{
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
	};
	char *result;
	size_t pos;

	if (base < 2 || base > 16 ||
		!(result = ft_strnew(sizeof_num(num, base))))
		return (NULL);
	pos = (base == 10 && num < 0);
	if (base == 10 && num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	result[0] = '0';
	while (num)
	{
		result[pos++] = alphabet[num % base];
		num /= base;
	}
	ft_strrev(result + (result[0] == '-'));
	return (result);
}