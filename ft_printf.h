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
	unsigned 			precision;
	unsigned			presence_dot;
	unsigned			width;
	enum types			modificate;
}						t_spec;

int						ft_printf(const char *str, ...);
t_spec					*ft_list_new();
void					ft_check_flags(const char **str, t_spec *list,
						va_list per);
void					ft_check_modificate(const char **str, t_spec *list);
unsigned				ft_check_format(char s);
int						ft_type_definition(const char **str, t_spec *list,
						va_list per);
void					ft_list_clear(t_spec *list);
void					ft_check_width_and_precision(const char **str,
						t_spec *list, va_list per);
int						ft_digitals(const char **str,
						t_spec *list, va_list per);
char					*ft_flagsfor_signed(int num, t_spec *list);
int						ft_right_aligned_with_precision(char *numb, char *str,
						t_spec *list, char *str_head);
int						ft_right_aligned_without_precision(char *numb,
						char *str, char *str_head);
int						ft_width_with_precision(char *numb, t_spec *list,
						char *str , char *str_head);
int						ft_width_noprecision(char *numb, t_spec *list,
						char *str, char *str_head);
int						ft_output_only_digital(char *numb);
int						ft_output_only_precision(char *numb, t_spec *list);
int						ft_start_pars_width(t_spec *list, char *numb);
char					*ft_unsigned_itoa_base(unsigned int num,
						int baze, unsigned size);
char					*ft_flagsfor_unsigned(unsigned int num,
						t_spec *list, int base, int size);

#endif
