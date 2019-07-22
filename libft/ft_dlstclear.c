/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:24:01 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/26 18:24:20 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **list)
{
	register t_dlist	*iter;
	t_dlist				*temp;

	if (!list || !*list)
		return ;
	iter = *list;
	while (iter)
	{
		temp = iter;
		free(iter->data);
		iter = iter->next;
		free(temp);
	}
	*list = NULL;
}
