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
	unsigned i;

	i = 0;
	ft_putnbr(num);
	while (num % 10)
	{
		i++;
		num /= 10;
	}
	return (i);
}

unsigned 		ft_str_system(const char *s, t_spec *list)
{
	ft_putstr(s);
	return (ft_strlen(s));
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
		list->modificate = 1;
	// Для вывода числа типа short int или unsigned short int.
	// Или для явного преобразования при выводе целочисленного числа к типу short int или unsigned short int.
	// Используется совместно с типами преобразования:d, i, o, u, x и X, n.
	else if (*str == 'h' && *(str + 1) == 'h')
		list->modificate = 2;
	// Для вывода числа типа char или unsigned char.
	// Или для явного преобразования при выводе целочисленного числа к типу char или unsigned char.
	// Используется совместно с типами преобразования:d, i, o, u, x и X, n.
	else if (*str == 'l' && *(str + 1) != 'l')
		list->modificate = 3;
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
	return (str);
}

char			*ft_check_flags(char *str, t_spec *list)
{
	while (*str != '.' && (!(ft_check_format(*str))))
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
		else
			list->shirina = list->shirina * 10 + (*str + '0');
		str++;
	}
	while (*str >= '0' && *str <= '9' && (!(ft_check_format(*str))))
	{
		list->tochnost = list->tochnost * 10 + (*str + '0');
		str++;
	}
	str = ft_check_modificate(str, list);
	return (str);
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
			{
				s = ft_check_flags(s, list);
				ft_list_add_end(&list, (ft_list_new()));
				list = list->next;
			}
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
