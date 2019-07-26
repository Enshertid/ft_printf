/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:17:47 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/22 14:53:53 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include <stdio.h>

#define MIN(spec) spec & 1
#define PLUS(spec) spec & 2
#define SPACE(spec) spec & 4
#define ZERO(spec) spec & 8
#define HASH(spec) spec & 16
#define PRECISION(spec) spec & 32
#define WIDTH(spec) spec & 64


enum types
{
						LONG_INT,
						CHAR,
						SHORT_INT,
						LONG_DOUBLE,
						LONG_LONG_INT
};

typedef struct	s_spec
{
	unsigned			flag_min;
	unsigned			flag_plus;
	unsigned			flag_space;
	unsigned			flag_zero;
	unsigned			hash;
	unsigned 			precision;
	unsigned			width;
	enum types			modificate;
}						t_spec;

int						ft_printf(const char *str, ...);
unsigned				ft_ten_signts_system(int num, t_spec *list);
unsigned				ft_str_system(const char *s, t_spec *list);
void					ft_list_add_end(t_spec **list, t_spec *new);
t_spec					*ft_list_new();
const char				*ft_check_flags(const char *str, t_spec *list);
const char				*ft_check_modificate(const char *str, t_spec *list);
unsigned				ft_check_format(char s);
int						ft_type_definition(const char *str, va_list per, t_spec *list);

#endif
