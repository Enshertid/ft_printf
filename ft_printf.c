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

unsigned 		ft_ten_signts_system(unsigned num, t_spec *list)
{
	unsigned	i;
	int 		sum;
	char 		*s;
	unsigned	j;

	i = 0;
	sum = num;
	if (num < 0)
	{
		ft_putchar('-');
		i++;
	}
	else if (num > 0 && list->flag_plus == 1)
	{
		ft_putchar('+');
		i++;
	}
	else if (num > 0 && list->flag_space == 1)
	{
		ft_putchar(' ');
		i++;
	}
	while (num % 10)
	{
		i++;
		num /= 10;
	}
	num = sum;
	if (list->tochnost == 0 && list->t_presence == 0
	&& list->shirina != 0 && list->flag_zero == 1 && list->flag_min == 0)
	{
		while (list->shirina)
		{
			i++;
			list->shirina--;
		}
		if (!(s = (char *) malloc(sizeof(char) * (i + 1))))
			exit(0);
		s[i] = '\0';
		j = i - 1;
		while (j != 0)
		{
			s[j] = 0;
			j--;
		}
	}
	else if (list->tochnost )
	return (j);
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
