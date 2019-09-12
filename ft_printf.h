/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:17:47 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/12 20:13:10 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stddef.h>

#define ull unsigned long long
#define ul unsigned long

# define TOSTR(a)	#a


# define BUFF_SIZE 1000
# define DBL_SIZE 1100
# define INT_PART 620
# define BUFF_SIZE 1000
# define LONG_MAX 4294967295
# define INT_MIN -2147483648
# define LLONG_MAX 9223372036854775807
# define LLONG_MIN -9223372036854775808
# define INT_MAX 2147483647
# define UINT_MAX 429496729
# define ULLONG_MAX 18446744073709551615
# define MAX_SIZE_T	(18446744073709551615llu)

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
	unsigned			flag_o;
	enum types			mod;
}						t_spec;

typedef struct s_buff
{
	char		buff[BUFF_SIZE];
	int			i;
	int			return_value;
}						t_buff;

typedef struct	s_double
{
	short				exp;
	short				sign;
	short				is_inf;
	short				is_nan;
	unsigned long long	mantissa;
}				t_double;

int						ft_printf(const char *str, ...);
t_spec					*ft_list_new();
t_buff					*ft_buf_new();
void					ft_check_flags(const char **str, t_spec *list);
void					ft_check_modificate(const char **str, t_spec *list);
void					ft_list_clear(t_spec *list);
void					ft_check_width(const char **str,
													 t_spec *list, va_list per);
void					ft_cleaning_buf(t_buff *buff);
void					ft_cleaningflags_char(t_spec *list);
void					ft_cleanbuff_andout(t_spec *list, t_buff *buff);
void					ft_str_out(char *str_out, t_buff *buff);
char					*ft_flag_unsign(ull num, t_spec *list,
												  char type);
char					*ft_flag_sign(long long int num, t_spec *list);
char					*ft_unsigned_itoa_base(ull num,int base , unsigned size);
char					*ft_parswidth(t_spec *list, char *numb);
char					*ft_output_only_precision(char *numb, t_spec *list);
char					*ft_digitals(const char **str, t_spec *list, va_list per);
char					*ft_type_definition(const char **str,
						t_spec *list, va_list per, t_buff *buff);
char					*ft_width_noprecision(char *numb, t_spec *list,
											  char *str, char *str_head);
char					*ft_width_with_precision(char *numb,
												 t_spec *list, char *str , char *str_head);
char					*ft_right_aligned_without_precision(char *numb,
															char *str, char *str_head);
char					*ft_right_aligned_with_precision(char *numb,
														 char *str, t_spec *list, char *str_head);
char					*ft_output_only_precision(char *numb, t_spec *list);
char					*ft_signed_char(const char **str,
									t_spec *list, char symbol, t_buff *buff);
char					*ft_charnotzero(t_spec *list, char *str_out, char symbol);
char					*ft_charzero(t_spec *list, char *str_out, t_buff *buff);
char					*ft_string_output(const char **str, t_spec *list, char *str_arg);
char					*ft_string_all(t_spec *list, char *str_arg, char *str_head, char *str_out);
char					*ft_string_all_width(t_spec *list, char *str_arg, char *str_head, char *str_out);
char					*ft_stringonly_precision(t_spec *list, char *str_arg, char *str_head, char *str_out);
char					*ft_stringonly_width(t_spec *list, char *str_arg, char *str_head, char *str_out);
char					*ft_pointer_output(const char **str, t_spec *list, ptrdiff_t per);
char					*ft_float(const char **str, va_list per, t_spec *list);

void					parse_double(long double *d, t_double *num);
void					mult(char *str, unsigned long multiplier);
void					add(char *str, char *plus);
int						offset(int i);
void					evaluate_mantissa(char *str, char *plus, ull mantissa, int iter);
char					*expand(char *str, size_t size);

char					*double_to_str(long double d, t_spec *format);
char					*get_integer_part(char *str, t_double num, t_spec *list);
int						offset(int i);
void					parse_double(long double *d, t_double *num);
void					mult(char *str, unsigned long multiplier);
void					add(char *str, char *plus);
void					evaluate_mantissa(char *str, char *plus, ull mantissa, int iter);
void					get_fract_part(char *str, t_double num);
char					*get_double(const char **str, va_list pre, t_spec *list);
char					*set_precision(char *str, t_spec *format);
char					*expand(char *str, size_t size);
#endif