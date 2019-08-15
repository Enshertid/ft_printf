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

# define BUFF_SIZE 1000
# define LONG_MAX 4294967295
# define INT_MIN -2147483648
# define LLONG_MAX 9223372036854775808
# define LLONG_MIN -9223372036854775809
# define INT_MAX 2147483647
# define UINT_MAX 429496729
# define ULLONG_MAX 18446744073709551615

enum types
{
	DEFAULT,
	CHAR,
	LONG,
	SHORT,
	LONG_LONG,
	LONG_DOUBLE
};

typedef struct	s_spec
{
	unsigned			flag_zero;
	unsigned			flag_minus;
	unsigned			flag_plus;
	unsigned			flag_space;
	unsigned			flag_hash;
	unsigned			precision;
	unsigned			presence_dot;
	unsigned			width;
	unsigned			flag_us;
	unsigned			flag_hashus;
	enum types			mod;
}						t_spec;

int						ft_printf(const char *str, ...);
t_spec					*ft_list_new();
void					ft_check_flags(const char **str, t_spec *list);
void					ft_check_modificate(const char **str, t_spec *list);
void					ft_list_clear(t_spec *list);
void					ft_check_width(const char **str,
													 t_spec *list, va_list per);
char					*ft_flag_unsign(unsigned long long int num, t_spec *list,
												  char type);
char					*ft_flag_sign(long long int num, t_spec *list);
char					*ft_unsigned_itoa_base(unsigned int num,int base , unsigned size);
char					*ft_parswidth(t_spec *list, char *numb);
char					*ft_output_only_precision(char *numb, t_spec *list);
char					*ft_digitals(const char **str, t_spec *list, va_list per);
char					*ft_type_definition(const char **str,
						t_spec *list, va_list per);
char					*ft_width_noprecision(char *numb, t_spec *list,
											  char *str, char *str_head);
char					*ft_width_with_precision(char *numb,
												 t_spec *list, char *str , char *str_head);
char					*ft_right_aligned_without_precision(char *numb,
															char *str, char *str_head);
char					*ft_right_aligned_with_precision(char *numb,
														 char *str, t_spec *list, char *str_head);
char					*ft_output_only_precision(char *numb, t_spec *list);
#endif