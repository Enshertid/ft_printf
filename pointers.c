#include "printf.h"

void print_pointer(t_buf *buf, t_format *format, va_list argptr)
{
	ptrdiff_t *ptr;
	char res[20];
	size_t size;

	if (!(ptr = va_arg(argptr, ptrdiff_t*)))
	{
		add_in_buf(buf, "(nil)", 5);
		return ;
	}
	ft_itoa((size_t)ptr, res, 16, 0);
	size = sizeof_num((size_t)ptr, 16);

	
	// if (format->width > size)
	// {

	// }
	
	
	
	if (format->flag_plus)
		add_in_buf2(buf, '+', 1);
	else if (format->flag_space)
		add_in_buf2(buf, ' ', 1);
	add_in_buf(buf, "0x", 2);



	add_in_buf(buf, res, size);
}