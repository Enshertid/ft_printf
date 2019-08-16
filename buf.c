#include "printf.h"

void add_in_buf2(t_buf *buf, int c, size_t n)
{
	size_t can_write;
	while (n)
	{
		can_write = ft_min(n, BUFF_SIZE - buf->pos);
		ft_memset(buf->buf + buf->pos, c, can_write);
		if ((buf->pos += can_write) == BUFF_SIZE)
		{
			write(1, buf->buf, BUFF_SIZE);
			buf->return_value += BUFF_SIZE;
			buf->pos = 0;
		}
		n -= can_write;
	}
}

void add_in_buf(t_buf *buf, const char *str, size_t n)
{
	size_t can_write;

	while (n)
	{
		can_write = ft_min(n, BUFF_SIZE - buf->pos);
		ft_memcpy(buf->buf + buf->pos, str, can_write);
		if ((buf->pos += can_write) == BUFF_SIZE)
		{
			write(1, buf->buf, BUFF_SIZE);
			buf->return_value += BUFF_SIZE;
			buf->pos = 0;
		}
		str += can_write;
		n -= can_write;
	}
}