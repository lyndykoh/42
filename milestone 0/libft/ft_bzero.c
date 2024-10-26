/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:49:23 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 15:22:18 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*p;

	p = (char *)str;
	while (n > 0)
	{
		p[n - 1] = 0;
		n--;
	}
}
//#include <strings.h>
//#include <stdio.h>
// int main(void)
//{
//    char str[] = "Hello world";
//    ft_bzero(str, 0);
//    printf("%s\n", str);
//    return (0);
//}
