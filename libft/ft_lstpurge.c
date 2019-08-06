/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:47:22 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/01 23:15:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpurge(t_list **list)
{
	register t_list *iter;
	register t_list *temp;

	if (!list || !*list)
		return ;
	iter = *list;
	while (iter)
	{
		free(iter->content);
		temp = iter;
		iter = iter->next;
		free(temp);
	}
	*list = NULL;
}
