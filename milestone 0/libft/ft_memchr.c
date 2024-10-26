/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:08 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/04 17:42:20 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
//#include <stdio.h>
//#include <string.h>

// int main() {
//   const char str[] = "hello";
//   const char ch = 'l';
//   char *ret;

//   ret = ft_memchr(str, ch, strlen(str));

//   printf("String after |%c| is - |%s|\n", ch, ret);

//   return(0);
//}