/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:11:52 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/12 12:15:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpopback(t_list **list)
{
	register t_list	*iter;
	t_list			*temp;

	if (!list || !*list)
		return ;
	iter = *list;
	temp = NULL;
	while (iter != (*list)->end)
	{
		temp = iter;
		iter = iter->next;
	}
	free(iter->content);
	free(iter);
	if (!temp)
		*list = NULL;
	else
		(*list)->end = temp;
}
