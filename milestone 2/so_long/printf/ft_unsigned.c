/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:29:17 by lkoh              #+#    #+#             */
/*   Updated: 2024/07/26 21:41:51 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n < 10)
	{
		c = n + '0';
		len += ft_putchar(c);
	}
	else
	{
		len += ft_unsigned(n / 10);
		c = (n % 10) + '0';
		len += ft_putchar(c);
	}
	return (len);
}
//#include <stdio.h>
// int	main(void)
//{
//	int a = -1;
//	int i = ft_unsigned(a);
//	p = printf("\n");
//	v = printf("%u\n", a);
//}