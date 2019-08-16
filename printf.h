/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:17:47 by ymanilow          #+#    #+#             */
/*   Updated: 2019/08/15 23:21:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

# define BUFF_SIZE 1

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "stdint.h"
# include "stddef.h"
# include "libft/includes/libft.h"
# include <stdio.h>

enum types
{
			DEFAULT,
			CHAR,
			LONG,
			SHORT,
			INT_64,
			SIZE_T,
			INTMAX_T,
			PTRDIFF_T,
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
	unsigned			precision;
	unsigned			dot_presence;
	unsigned			width;
	enum types			modificate;
	char				type;
}						t_format;

int 		ft_printf(const char *str, ...);
void		print_digital(t_buf *buf, t_format *format, va_list argptr);
void		print_alphas(t_buf *buf, t_format *format, va_list argptr);
void		print_pointer(t_buf *buf, t_format *format, va_list argptr);
void		add_in_buf2(t_buf *buf, int c, size_t n);
void		add_in_buf(t_buf *buf, const char *str, size_t n);
void get_format(const char **str, t_format *format, va_list argptr);
void print_float(t_format *format, va_list argptr);

#endif
