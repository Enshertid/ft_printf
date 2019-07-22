/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:23:36 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/26 18:23:37 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstadd(t_dlist **list, t_dlist *new)
{
	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		new->end = new;
	}
	else
	{
		new->next = *list;
		new->end = (*list)->end;
		(*list)->prev = new;
		*list = new;
	}
}
