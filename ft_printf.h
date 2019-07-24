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

typedef struct	s_spec
{
	unsigned		flag_min;
	unsigned		flag_plus;
	unsigned		flag_space;
	unsigned		flag_zero;
	unsigned		reshetka;
	unsigned 		tochnost;
	unsigned		shirina;
	unsigned		modificate;
	struct s_spec	*next;
}				t_spec;

unsigned				ft_printf(const char *str, ...);
unsigned				ft_ten_signts_system(unsigned num, t_spec *list);
unsigned				ft_str_system(const char *s, t_spec *list);
void					ft_list_add_end(t_spec **list, t_spec *new);
t_spec					*ft_list_new();
char					*ft_check_flags(char *str, t_spec *list);
char					*ft_check_modificate(char *str, t_spec *list);
unsigned				ft_check_format(char s);


#endif
