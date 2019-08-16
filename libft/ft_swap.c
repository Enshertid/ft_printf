/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:42:55 by user              #+#    #+#             */
/*   Updated: 2019/08/12 12:39:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	unsigned char temp[size];

	if (a == b)
		return ;
	ft_memcpy(temp, a, size);
	ft_memmove(a, b, size);
	ft_memcpy(b, temp, size);
}