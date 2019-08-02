/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:20:07 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/01 22:16:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	register size_t start;
	register size_t end;
	char temp;

	if (!str)
		return ;
	start = 0;
	end = ft_strlen(str) - 1;
	if (end <= start)
		return ;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		++start;
		--end;
	}
}
