/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:37:30 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/16 16:39:56 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_charrdel(char ***arr)
{
	size_t iter;

	if (!arr || !*arr)
		return ;
	iter = 0;
	while ((*arr)[iter])
	{
		free((*arr)[iter]);
		(*arr)[iter] = NULL;
		++iter;
	}
	free(*arr);
	*arr = NULL;
}
