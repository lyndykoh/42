/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:52:42 by lkoh              #+#    #+#             */
/*   Updated: 2024/07/26 17:39:47 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, char c)
{
	char	*hex;
	int		len;

	len = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_printhex(n / 16, c);
	}
	c = hex[n % 16];
	len += ft_putchar(c);
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