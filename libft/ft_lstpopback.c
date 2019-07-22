/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:11:52 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/23 13:11:54 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delelem(t_list *elem)
{
	free(elem->content);
	free(elem);
}

void		ft_lstpopback(t_list **list)
{
	t_list *iter;

	if (!list || !*list)
		return ;
	if (*list == (*list)->end)
	{
		delelem(*list);
		*list = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next != (*list)->end)
			iter = iter->next;
		delelem(iter->next);
		iter->next = NULL;
		(*list)->end = iter;
	}
}
