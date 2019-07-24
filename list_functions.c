/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:00:55 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/23 13:00:56 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec		*ft_list_new()
{
	t_spec	*list;
	int		i;

	if (!(list = malloc(sizeof(t_spec))))
		return (NULL);
	i = 0;
	list->flag_space = 0;
	list->flag_plus = 0;
	list->flag_min = 0;
	list->flag_zero = 0;
	list->shirina = 0;
	list->tochnost = 0;
	list->modificate = 0;
	list->next = NULL;
	return (list);
}

void		ft_list_add_end(t_spec **list, t_spec *new)
{
	t_spec *tmp;

	if (*list && new)
	{
		tmp = *list;
	while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		*list = tmp;
	}
}
