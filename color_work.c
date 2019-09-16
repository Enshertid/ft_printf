#include "ft_printf.h"

void	ft_check_fd(const char **str, t_spec *list, va_list per)
{
	if (**str == 'f')
	{
		(*str)++;
		if (**str == 'd')
		{
			list->fd = (va_arg(per, int));
			(*str)++;
		}
		else
			(*str)--;
	}
}

void		ft_check_othercolor(const char **str, t_spec *list)
{
	if (**str == 'b')
		list->color = BLUE;
	else if (**str == 'P')
		list->color = PURPLE;
	else if (**str == 'p')
		list->color = PINK;
	else if (**str == 'O')
		list->color = ORANGE;
	else if (**str == 'g')
		list->color = GREY;
	else if (**str == 'T')
		list->color = TURQUOISE;
}

void		ft_check_color(const char **str, t_spec *list)
{
	if (**str == 'k')
	{
		(*str)++;
		if (**str == 'W')
			list->color = WHITE;
		else if (**str == 'B')
			list->color = BLACK;
		else if (**str == 'R')
			list->color = RED;
		else if (**str == 'Y')
			list->color = YELLOW;
		else if (**str == 'G')
			list->color = GREEN;
		else
			ft_check_othercolor(str, list);
		(*str) += (**str == 'W' || **str == 'B' || **str == 'R' ||
				**str == 'Y' || **str == 'G' || **str == 'P' || **str == 'p' ||
				**str == 'O' || **str == 'T' || **str == 'g' || **str == 'b');
	}
}

void		ft_end_color_to_buff(t_buff *buff, t_spec *list)
{
	char str[5] = {"\e[0m"};
	int j;
	j = 0;
	if (buff->i + 5 > BUFF_SIZE && list->fd > 0)
	{
		write(list->fd, buff->buff, buff->i);
		write(list->fd, "\e[0m", 5);
		buff->return_value += 5;
		buff->i = 0;
		ft_strclr(buff->buff);
	}
	else if (list->fd > 0)
	{
		while(j < 4 && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str[j++];
	}
}

void		ft_add_color_to_buff(t_buff *buff, t_spec *list)
{
	int j;
	static const char str[11][12] = {
			"\e[38;5;255m", "\e[38;5;232m", "\e[38;5;001m",
			"\e[38;5;040m", "\e[38;5;011m", "\e[38;5;075m",
			"\e[38;5;105m", "\e[38;5;013m", "\e[38;5;130m",
			"\e[38;5;007m", "\e[38;5;123m",
	};

	j = 0;
	if (buff->i + 12 > BUFF_SIZE && list->fd > 0)
	{
		write(list->fd, buff->buff, buff->i);
		write(list->fd, str[list->color], 12);
		buff->return_value += 12;
		buff->i = 0;
		ft_strclr(buff->buff);
	}
	else if (list->fd > 0)
	{
		while(j < 11 && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str[list->color][j++];
	}
}
