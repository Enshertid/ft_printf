/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filling_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:17:14 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/24 17:17:18 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char			*ft_check_flags(char *str, t_spec *list)
{
	while (*str != '.' && (!(ft_check_format(*str))) && (!ft_check_modificate(*str, list)))
	{
		if (*str == '-')
			list->flag_min = 1;
		else if (*str == '+')
			list->flag_plus = 1;
		else if (*str == ' ')
			list->flag_space = 1;
		else if (*str == '0' && *(++str) != '.')
		{
			list->flag_zero = 1;
			str--;
		}
		else if (*str == '#')
			list->reshetka = 1;
		else
			list->shirina = list->shirina * 10 + (*str - '0');
		str++;
	}
	if(*str == '.')
	{
		list->t_presence = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		list->tochnost = list->tochnost * 10 + (*str - '0');
		str++;
	}
	str = ft_check_modificate(str, list);
	return (str);
}

unsigned				ft_check_format(char s)
{
	if(s == 'd' || s == 'i' || s == 's' || s == 'u'
	   || s == 'o' || s == 'x' || s == 'X' || s == 'c' || s == 'S'
	   || s == 'p' || s == 'n'|| s == 'f' || s == 'F')
		return (1);
	else
		return (0);
}

char			*ft_check_modificate(char *str, t_spec *list)
{
	if (*str == 'h' && *(str + 1) != 'h')
	{
		list->modificate = 1;
		str--;
	}
		// Для вывода числа типа short int или unsigned short int.
		// Или для явного преобразования при выводе целочисленного числа к типу short int или unsigned short int.
		// Используется совместно с типами преобразования:d, i, o, u, x и X, n.
	else if (*str == 'h' && *(str + 1) == 'h')
		list->modificate = 2;
		// Для вывода числа типа char или unsigned char.
		// Или для явного преобразования при выводе целочисленного числа к типу char или unsigned char.
		// Используется совместно с типами преобразования:d, i, o, u, x и X, n.
	else if (*str == 'l' && *(str + 1) != 'l')
	{
		list->modificate = 3;
		str--;
	}
		//Для вывода числа типа long int или unsigned long int.
		// Или для явного преобразования при выводе целочисленного числа к типу long int или unsigned long int.
		// Используется совместно с типами преобразования:d, i, o, u, x и X, n.
	else if (*str == 'l' && *(str + 1) == 'l')
		list->modificate = 4;
		// Для вывода числа типа long long int или unsigned long long int.
		// Или для явного преобразования при выводе целочисленного числа к типу long long int или unsigned long long int.
		// Используется совместно с типами преобразования:d, i, o, u, x и X, n.
	else if (*str == 'L')
		list->modificate = 5;
	// Для вывода числа типа long double.
	// Или для явного преобразования при выводе числа c плавающей точкой к типу long double.
	// Используется совместно с типами преобразования:e, E, f, g и G.
	str++;
	return (str);
}