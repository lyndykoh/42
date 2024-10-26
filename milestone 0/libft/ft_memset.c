/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:20 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/05 11:55:35 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (str);
}
//#include <stdio.h>
// int main(void)
//{
//    char str[] = "Hello world";
//    ft_memset(str, '!', 5);
//    printf("%s\n", str);
//    return (0);
//}