/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:23:15 by dbendu            #+#    #+#             */
/*   Updated: 2019/08/01 23:20:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(str) + 1;
	new_str = (char*)malloc(size);
	if (!new_str)
		return (NULL);
	return ((char*)ft_memcpy(new_str, str, size));
}
