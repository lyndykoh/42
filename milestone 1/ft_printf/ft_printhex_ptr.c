/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:52:42 by lkoh              #+#    #+#             */
/*   Updated: 2024/07/26 21:38:10 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex_rec(unsigned long n, char *hex)
{
	char	c;
	int		num;

	num = 0;
	if (n >= 16)
	{
		num += ft_printhex_rec(n / 16, hex);
	}
	c = hex[n % 16];
	ft_putchar(c);
	return (num);
}

int	ft_printhex_ptr(unsigned long n, char c)
{
	char			*hex;
	int				len;
	unsigned long	temp;

	len = 0;
	temp = n;
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	while (temp)
	{
		temp /= 16;
		len++;
	}
	temp = ft_printhex_rec(n, hex);
	return (len);
}
/*#include <stdio.h>
int	main(void)
{
	int a = 5;
	int *ptr = &a;
	int i = ft_printhex(a, 'x');
	printf("\n%d\n", i);
	printf("%x\n", a);
	printf("%p\n", ptr);
}*/