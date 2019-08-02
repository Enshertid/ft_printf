//
// Created by Yaxley Manilow on 2019-08-01.
//

#include "ft_printf.h"

char				*ft_flagsfor_signed(int num, t_spec *list)
{
	char				*numb;

	if (num > 0 && list->flag_plus == 1)
	{
		numb = ft_itoa(-num);
		numb[0] = '+';
	}
	else if (num > 0 && list->flag_space == 1)
	{
		numb = ft_itoa(-num);
		numb[0] = ' ';
	}
	else //(num < 0 || num > 0)
		numb = ft_itoa(num);
	if (num < 0)
	return (numb);
}

char				*ft_fillingflag_hexlow(char *numb, int base, int size, t_spec *list)
{
	char		*flag;
	size_t		i;

	int k = ft_strlen(numb);
	if (base == 16)
	{
		flag = ft_memalloc(k + 3);
		flag[0] = '0';
		if (size == 0)
			flag[1] = 'x';
		else
			flag[1] = 'X';
		i = 2;
	}
	else
	{
		flag = ft_memalloc(ft_strlen(numb) + 2);
		flag[0] = '0';
		i = 1;
	}
	int j = 0;
	while (numb[j])
	{
		flag[i++] = numb[j++];
	}
	free(numb);
	return (flag);
}

char				*ft_flagsfor_unsigned(unsigned int num, t_spec *list,
					int base, int size)
{
	char				*numb;

	numb = ft_unsigned_itoa_base(num, base, size);
	if (list->flag_hash == 1 && (base == 16 || base == 8))
		return (ft_fillingflag_hexlow(numb, base, size, list));
	else
		return (numb);
}