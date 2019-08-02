/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:13:17 by user              #+#    #+#             */
/*   Updated: 2019/08/02 21:04:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	sizeof_num(int num, unsigned base)
{
	size_t size;

	if (!num)
		return (1);
	if (num == MIN_INT)
		return (10);
	if (base == 10 && num < 0)
		num = -num;
	size = 0;
	while (num)
	{
		++size;
		num /= base;
	}
	return (size);
}