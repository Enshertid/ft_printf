/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:23:15 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/08 20:23:17 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	register char	*new_str;
	size_t			size;

	new_str = NULL;
	size = ft_strlen(str) + 1;
	new_str = (char*)malloc(size);
	if (!new_str)
		return (NULL);
	return ((char*)ft_memcpy(new_str, str, size));
}
