/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:23:49 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/26 18:23:50 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstappend(t_dlist **list, t_dlist *new)
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
		new->prev = (*list)->end;
		new->prev->next = new;
		(*list)->end = new;
	}
}
