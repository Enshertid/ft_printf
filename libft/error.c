/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:08:29 by dbendu            #+#    #+#             */
/*   Updated: 2019/07/30 20:09:23 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(const char *error_msg, int error_code)
{
	write(1, error_msg, ft_strlen(error_msg));
	exit(error_code);
}
