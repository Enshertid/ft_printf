/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:17:47 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/05 14:02:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

# define BUFF_SIZE 1024

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include <stdio.h>

enum types
{
			DEFAULT,
			CHAR,
			LONG,
			SHORT,
			LONG_LONG,
			LONG_DOUBLE
};

typedef struct	s_buf
{
	char buf[BUFF_SIZE + 1];
	size_t pos;
	int return_value;
}				t_buf;

typedef struct	s_format
{
	unsigned			flag_zero;
	unsigned			flag_minus;
	unsigned			flag_plus;
	unsigned			flag_space;
	unsigned			flag_hash;
	unsigned 			precision;
	unsigned			presence_dot;
	unsigned			width;
	enum types			modificate;
	char				type;
}						t_format;

int 		ft_printf(const char *str, ...);

#endif
