/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:03:42 by lkoh              #+#    #+#             */
/*   Updated: 2024/07/26 21:41:17 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	char	c;
	int		ori;

	ori = n;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + '0';
	}
	else
	{
		ft_putnbr(n / 10);
		c = (n % 10) + '0';
	}
	write(1, &c, 1);
	return (intlen(ori));
}
/*#include <stdio.h>
int	main(void)
{
	int a = -456;
	int i = ft_putnbr(a);
	printf("\n");
	printf("%d\n", i);
	printf("%d\n", a);
}*/