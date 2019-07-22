/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:17:15 by ymanilow          #+#    #+#             */
/*   Updated: 2019/07/22 14:17:21 by ymanilow         ###   ########.fr       */
/* ************************************************************************** */

#include "ft_printf.h"

//int 		ft_sum(int count, ...)
//{
//	va_list	per;
//	int i;
//
//	va_start (per, count);
//
//	i = 0;
//	while(count)
//	{
//		i = i + va_arg(per, int);
//		count--;
//	}
//	va_end(per);
//	return (i);
//}
//
///*                                                                            */
//int		ft_choose_your_var(void)
//{
//	int a;
//
//	printf(" 3 - exit\n 1 - print num 4 \n 2 - print num 5\n");
//	scanf("%d", &a);
//	return (a);
//}
//
//int		ft_exit(void)
//{
//	printf("exit code 0\n");
//	exit(0);
//}
//
//int 	ft_print_5(void)
//{
//	printf("5\n");
//	return(0);
//}
//
//int 	ft_print_4(void)
//{
//	printf("4\n");
//	return (0);
//}

int main()
{
//	int sum;
	int return_value;
	int original_return_value;

    original_return_value = printf("%d\n%s\n%i\n", 1234, "abc", 4321);
    return_value = ft_printf("%d\n%s\n%d\n", 1234, "abc", 4321);
//    sum = ft_sum(4,1,2,3,4);


//	int(*a [10])(void);
//	a[0] = ft_choose_your_var;
//	a[1] = ft_print_4;
//	a[2] = ft_print_5;
//	a[3] = ft_exit;
//	a[a[0]()]();
	printf("ft_printf_return_value == %d\n", return_value);
	printf("original_return_value == %d\n", original_return_value);
	return (0);
}
