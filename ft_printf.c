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

int			ft_type_definition(const char *format, va_list per, t_spec *list)
{
	printf ("%s", format);
	return (ft_strlen(format));
//	if (*format == 'd' || *format == 'i')
////					// Вывод целого числа со знаком в десятичной систем счисления.
////					// По умолчанию выводится число размером sizeof( int )
////					// С правым выравниванием, указанием знака только для отрицательных чисел.
//		ft_ten_signts_system(va_arg(per,int), list);
//	else if (*format == 's')
//		ft_format_system(va_arg(per, char*), list);
////					num += ft_format_system(va_arg(per, char*));
//		// Вывод строки, на которую ссылается указатель в аргументе функции printf.
//		// Строка выводится пока не будет встречен символ конец строки (/0).
////					// По умолчанию строка должна обозначаться как char*.
////					// Если указан модификатор l, то строка интерпитируется как wchar_t*.
//	else if (*format == 'u')
//	{}
//		// Вывод целого числа без знака в десятичной систем счисления.
////				// По умолчанию выводится число размером sizeof( int ), с правым выравниванием.
//	else if (*format == 'o')
//	{}
//		// целое число без знака в восьмеричной системе счисления
//	else if (*format == 'x' || *format =='X')
//	{}
//		// Вывод целого числа без знака в шестнадцетеричной систем счисления.
////				// Причем для преобразования x используются символы abcdef, а для X - символы ABCDEF.
////				// По умолчанию выводится число размером sizeof( int ), с правым выравниванием.
//	else if (*format == 'c')
//	{}
//		// Вывод символа, соответстветсвующего числу указанному в аргументе функции.
////				// По умолчанию число приводится к типу unsigned char.
//	else if (*format == 'S')
//	{}
//		// Аналогичен преобразованию s с модификатором l (ls).
//	else if (*format == 'p')
//	{}
//		// Вывод указателя. Результат ввода зависит от архитектуры и используемого компилятрора.
////				// Например, на 16 битной платформе MS-DOS вывод будет иметь вид типа FFAB:1402.
////				// А на 32-битной платформе с плоской адресацией - 00FC0120.
//	else if (*format == 'n')
//	{}
//		// Запись по адресу, указанному в аргументе функции, количества выведенных символов функцией pr-f до встречи преобразователя %n.
////				// При обработке преобразователя %n никакого вывода символов не производится.
//	else if (*format == 'f' || *format == 'F')
//	{}
//	// Вывод числа с плавающей точкой в виде [-]dddd.ddd.
////				// По умолчанию выводится число с точностью 6, если число по модулю меньше единицы, то пред десятично точкой выводится ноль.
////				// знак указывается только для отрицательных чисел, с правым выравниванием.
////				// Размер по умолчанию sizeof( double ).y
//	format++;
//	ft_list_add_end(&list, (ft_list_new()));
}

int					ft_second_step(const char **format, va_list per, t_spec *list)
{
	int return_value;

	list = ft_list_new();
	format++;
	if(!(ft_check_format(**format)))
		format = ft_check_flags(*format, list);
	list->width = ft_atoi(*format);
	if (**format == '*')
	{
		list->width = va_arg(per, int);
		format++;
	}
	while (ft_isdigit(**format))
		format++;
	if (**format == '.')
		list->precision = ft_atoi(++(*format));
	if (**format == '*')
	{
		list->precision = va_arg(per,int);
		format++;
	}
	while (ft_isdigit(**format))
		format++;
	if (ft_check_modificate(*format, list))
		format++;
	return_value = ft_type_definition(*format, per, list);
	return (return_value);
}

int 		ft_first_step(const char *format, va_list per)
{
	const char		*output;
	t_spec			*list;
	int				return_value;

	output = format;
	list = ft_list_new();
	return_value = 0;
	while (*format)
	{
		while (*format != '%' && *(format + 1) != '%')
			format++;
		write (1, output, format - output);
		return_value += (format - output);
		format++;
		return_value += ft_second_step(&format, per, list);
	}
	return (return_value);
}

int 		ft_printf(const char *format, ...)
{
	va_list		per;
	int			return_value;

	va_start(per, format);
	return_value = ft_first_step(format, per);
	va_end(per);
	return (return_value);
}
