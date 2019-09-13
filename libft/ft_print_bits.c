/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:13:45 by user              #+#    #+#             */
/*   Updated: 2019/09/11 11:18:32 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bits(void *a, size_t size)
{
	char	buf[size * 8 + size];
	size_t	pos;
	int		byte;
	int		offset;

	pos = 0;
	byte = size;
	while (--byte >= 0)
	{
		offset = 8;
		while (--offset >= 0)
			buf[pos++] = '0' + ((*((char*)a + byte) >> offset) & 1);
		buf[pos++] = ' ';
	}
	write(1, buf, size * 8 + size);
}