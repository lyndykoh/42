/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:00:53 by lkoh              #+#    #+#             */
/*   Updated: 2024/07/26 16:46:21 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	unsigned long	add;
	int				i;

	i = 0;
	if (ptr == NULL)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	add = (unsigned long)ptr;
	ft_putstr("0x");
	i += 2;
	i += ft_printhex_ptr(add, 'x');
	return (i);
}
/*#include <stdio.h>
int	main(void)
{
	char *n;
	void *p;
	int a;
	n = "hello world";
	p = &n;
	a = ft_printptr(p);
	printf("\nadd of ptr: %p\n", p);
	printf("output len: %i\n", a);
}*/