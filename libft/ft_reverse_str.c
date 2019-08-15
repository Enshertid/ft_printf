/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:20:07 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/08 20:20:08 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_str(char *str)
{
	register size_t start;
	register size_t end;

	if (!str)
		return ;
	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
		ft_cswap((str + start++), (str + end--));
}
