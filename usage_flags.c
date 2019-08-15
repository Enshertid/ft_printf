#include "ft_printf.h"

char				*ft_flagsfor_signedzero(t_spec *list, char *numb)
{
	if (list->flag_plus == 1 || list->flag_space == 1)
	{
		if (list->presence_dot == 0)
		{
			numb = ft_strnew(2);
			numb[1] = '0';
		}
		else
			numb = ft_strnew(1);
		numb[0] = list->flag_plus == 1 ? '+' : ' ';
		list->flag_us++;
	}
	else if ((list->flag_plus == 0 && list->flag_space == 0) && list->presence_dot == 1)
		numb = ft_strnew(0);
	else
	{
		numb = ft_strnew(1);
		numb[0] = '0';
	}
	return (numb);
}

char				*ft_flag_sign(long long int num, t_spec *list)
{
	char				*numb;

	numb = NULL;
	if (num > 0 && (list->flag_plus == 1 || list->flag_space == 1))
	{
		numb = ft_itoa(-num);
		numb[0] = list->flag_plus == 1 ? '+' : ' ';
		list->flag_us++;
	}
	else if (num < 0)
	{
		numb = ft_itoa(num);
		list->flag_us++;
	}
	else if (num == 0)
		return (ft_flagsfor_signedzero(list, numb));
	else
		numb = ft_itoa(num);
	return (numb);
}

char				*ft_fillingflag_hex(char *numb, int size, int base, t_spec *list)
{
	char			*flagged;
	size_t			i;
	size_t			j;

	if(base == 16)
	{
		flagged = ft_strnew(ft_strlen(numb) + 2);
		flagged[0] = '0';
		flagged[1] = (size == 0) ? 'x' : 'X';
		i = 2;
	}
	else
	{
		flagged = ft_strnew(ft_strlen(numb) + 1);
		flagged[0] = '0';
		i = 1;
	}
	list->flag_us += i;
	list->flag_hashus = 1;
	j = 0;
	while (numb[j])
		flagged[i++] = numb[j++];
	free(numb);
	return (flagged);
}

char				*ft_flagsfor_unsignedzero(char *numb, int base, t_spec *list)
{
	char			*flagged;

	if (list->flag_hash == 1 && base == 8 && list->presence_dot == 1 && list->precision == 0)
	{
		flagged = ft_strnew(1);
		flagged[0] = '0';
		free(numb);
	}
	else if (list->presence_dot == 1)
	{
		flagged = ft_strnew(0);
		free(numb);
	}
	else
	{
		flagged = ft_strnew(1);
		flagged[0] = '0';
		free(numb);
	}
	return (flagged);
}

char				*ft_flag_unsign(unsigned long long int num, t_spec *list,
					char type)
{
	char	*numb;
	int		base;
	int		size;

	size = 0;
	if (type == 'u' || type == 'o')
		base = type == 'u' ? 10 : 8;
	else
		base = 16;
	if (type == 'X')
		size = 1;
	if (num != 0)
	{
		numb = ft_unsigned_itoa_base(num, base, size);
		if (list->flag_hash == 1 && (base == 16 || base == 8))
			return (ft_fillingflag_hex(numb, size,base, list));
		else
			return (numb);
	}
	else
	{
		numb = ft_unsigned_itoa_base(num, base, size);
		return (ft_flagsfor_unsignedzero(numb,base, list));
	}
}