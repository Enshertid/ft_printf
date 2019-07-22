/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:18:45 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/08 20:18:46 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == MIN_INT)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nbr >= 10)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd(nbr % 10 + '0', fd);
		}
		else if (nbr < 0)
		{
			write(fd, "-", sizeof(char));
			ft_putnbr_fd(-nbr, fd);
		}
		else
			ft_putchar_fd(nbr % 10 + '0', fd);
	}
}
