/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:14:35 by dbendu            #+#    #+#             */
/*   Updated: 2019/09/11 10:33:02 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_isnegative_topos(long long int *num, size_t *is_negative)
{
	if (*num < 0)
	{
		*is_negative = 1;
		*num = -*num;
	}
	else
		*is_negative = 0;
}

static size_t	ft_size_of_num(long long int n)
{
	size_t size;

	size = 0;
	while (n /= 10)
		++size;
	return (size + 1);
}

char			*ft_itoa(long long int num)
{
	register char	*str;
	register size_t	size;
	size_t			sign;

	if (num == (-LLONG_MAX - 1LL))
		return (ft_strdup("-9223372036854775808"));
	size = ft_size_of_num(num) + 1 + (num < 0);
	ft_isnegative_topos(&num, &sign);
	if (!(str = (char*)malloc(size)))
		return (NULL);
	str[--size] = '\0';
	while (size--)
	{
		str[size] = (num % 10 + 48);
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
