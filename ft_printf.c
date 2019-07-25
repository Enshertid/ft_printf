/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/22 14:53:45 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 			ft_done_for_aligning_left_with_sight(int num, t_spec *list)
{
	char			*s;
	char 			*s1;
	char 			*str;
	unsigned 		i;

	if (num < 0)
		s = ft_itoa(num);
	else if (num > 0)
	{
		s = ft_itoa(num * -1);
		s[0] = '+';
	}
	if (list->tochnost > (ft_strlen(s) - 1))
	{
		i = list->tochnost - ft_strlen(s) - 1;
		str = ft_strnew(i);
		ft_bzero (str, i);
	}
	s1 = ft_strnew(list->shirina + 1);
	ft_bzero(s1, ft_strlen(s1));
	str = ft_strjoin(s, s1);
	free(s1);
	free(s);
}

unsigned 		ft_ten_signts_system(int num, t_spec *list)
{
	unsigned		i;
	unsigned		j;
	char 			*s;
	char 			*s1;

	if (list->flag_plus == 1 && list->flag_min == 1)
		ft_done_for_aligning_left_with_sight(num, list);
}

unsigned 		ft_str_system(const char *s, t_spec *list)
{
	ft_putstr(s);
	return (ft_strlen(s));
}


unsigned				ft_printf(const char	*str, ...)
{
	va_list		per;
	t_spec		*list;
	t_spec		*head;
	int 		num;
	char 		*s;

	num = 0;
	va_start(per, str);
	s = str;
	list = ft_list_new();
	head = list;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if(!(ft_check_format(*s)))
				s = ft_check_flags(s, list);
			list->shirina = ft_atoi(s);
			if (*s == "*")
			{
				list->shirina = va_arg(per, int);
				s++;
			}
			while (ft_isdigit(*s))
				s++;
			if (*s == '.')
				list->tochnost = ft_atoi(++s);
			if (*s == '*')
			{
				list->tochnost = va_arg(per,int);
				s++;
			}
			while (ft_isdigit(*s))
				s++;
			if (ft_check_modificate(s, list))
				s++;
			if (*s == 'd' || *str == 'i')
//					// Вывод целого числа со знаком в десятичной систем счисления.
//					// По умолчанию выводится число размером sizeof( int )
//					// С правым выравниванием, указанием знака только для отрицательных чисел.
				num += ft_ten_signts_system(va_arg(per,int), list);
			else if (*s == 's')
				num += ft_str_system(va_arg(per, char*), list);
//					num += ft_str_system(va_arg(per, char*));
					// Вывод строки, на которую ссылается указатель в аргументе функции printf.
					// Строка выводится пока не будет встречен символ конец строки (/0).
//					// По умолчанию строка должна обозначаться как char*.
//					// Если указан модификатор l, то строка интерпитируется как wchar_t*.
			else if (*s == 'u')
			{}
				// Вывод целого числа без знака в десятичной систем счисления.
//				// По умолчанию выводится число размером sizeof( int ), с правым выравниванием.
			else if (*s == 'o')
			{}
				// целое число без знака в восьмеричной системе счисления
			else if (*s == 'x' || *str =='X')
			{}
				// Вывод целого числа без знака в шестнадцетеричной систем счисления.
//				// Причем для преобразования x используются символы abcdef, а для X - символы ABCDEF.
//				// По умолчанию выводится число размером sizeof( int ), с правым выравниванием.
			else if (*s == 'c')
			{}
				// Вывод символа, соответстветсвующего числу указанному в аргументе функции.
//				// По умолчанию число приводится к типу unsigned char.
			else if (*s == 'S')
				{}
				// Аналогичен преобразованию s с модификатором l (ls).
			else if (*s == 'p')
			{}
				// Вывод указателя. Результат ввода зависит от архитектуры и используемого компилятрора.
//				// Например, на 16 битной платформе MS-DOS вывод будет иметь вид типа FFAB:1402.
//				// А на 32-битной платформе с плоской адресацией - 00FC0120.
			else if (*s == 'n')
			{}
				// Запись по адресу, указанному в аргументе функции, количества выведенных символов функцией pr-f до встречи преобразователя %n.
//				// При обработке преобразователя %n никакого вывода символов не производится.
			else if (*s == 'f' || *str == 'F')
			{}
				// Вывод числа с плавающей точкой в виде [-]dddd.ddd.
//				// По умолчанию выводится число с точностью 6, если число по модулю меньше единицы, то пред десятично точкой выводится ноль.
//				// знак указывается только для отрицательных чисел, с правым выравниванием.
//				// Размер по умолчанию sizeof( double ).y
			s++;
			ft_list_add_end(&list, (ft_list_new()));
			list = list->next;
		}
		else
		{
			ft_putchar(*s);
			num++;
			s++;
		}
	}
	va_end(per);
	return (num);
}
