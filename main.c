
#include "ft_printf.h"
//typedef struct	s_format
//{
//	unsigned left_align;
//	unsigned right_align;
//	unsigned show_sign;
//	unsigned fill_sign_cell;
//	unsigned fill_spaces;
//	unsigned fill_zeros;
//	unsigned width;
//	unsigned presicion;
//	unsigned type;
//}				t_format;
//
//void	get_flags(const char **format, t_format *info)
//{
//	while (**format == '-' || **format == '+' ||
//			**format == ' ' || **format == '0')
//	{
//		if (**format == '-')
//		{
//			info->right_align = 0;
//			info->left_align = 1;
//		}
//		else if (**format == '+')
//			info->show_sign = 1;
//		else if (**format == ' ')
//			info->fill_sign_cell = 1;
//		else if (**format == '0')
//		{
//			info->fill_spaces = 0;
//			info->fill_zeros = 1;
//		}
//		++*format;
//	}
//}
//
//
//
//void	get_width_presicion_type(const char **format, t_format *info)
//{
//	const char *dot;
//
//	dot = ft_memchr(*format, '.', ft_strlen(*format));
//	if (dot)
//		info->width = ft_atoi(*format);
//	*format = dot + 1;
//	info->presicion = ft_atoi(*format);
//	while (!ft_isalpha(**format))
//		++*format;
//	info->type = **format++;
//}
//
//
//t_format *fill_info(const char **format)
//{
//	t_format *info;
//
//	info = (t_format*)malloc(sizeof(t_format));
//	ft_memset(info, 0, sizeof(info));
//	info->fill_spaces = 1;
//	info->right_align = 1;
//	get_flags(format, info);
//	get_width_presicion_type(format, info);
//	return (info);
//}
//
//void processing(const char **format, t_list **output)
//{
//	t_format *info;
//
//	info = fill_info(format);
//	if (info->fill_sign_cell)
//		write(1, "flag \" \" is active\n", 20);
//	if (info->fill_spaces)
//		write()
//}
//
//t_list *get_output(const char *format/*, va_list argptr*/)
//{
//	t_list *output;
//	const char *prev;
//
//	output = NULL;
//	prev = format;
//	while ((format = ft_memchr(format, '%', ft_strlen(format))))
//	{
//		if (format - prev > 1)
//			ft_lstappend(&output, ft_lstnew(prev, format - prev));
//		processing(format, &output);
//		prev = ++format;
//	}
//	return (output);
//}
//
//int ft_printf(const char *format, ...)
//{
//	int symbols;
//	t_list *output;
//	t_list *iter;
//	va_list argptr;
//
//	va_start(argptr, format);
//	output = get_output(format/*, argptr*/);
//	va_end(argptr);
//	symbols = 0;
//	iter = output;
//	while (iter)
//	{
//		write(1, iter->content, ft_strlen(iter->content));
//		write(1, "\n", 1);
//		symbols += ft_strlen(iter->content);
//		iter = iter->next;
//	}
//	ft_lstclear(&output);
//	return (symbols);
//}

int	main(void)
{
	int a = ft_printf("first_primer:%dsecondblabla", 525);
//	int b = printf("%+0.10s\n", "vot tak");
//	printf("original_return_value = %d\n ft_pritnf_return_value = %%\n", b);


	return (0);
}