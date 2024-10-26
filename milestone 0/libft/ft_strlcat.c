/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:50 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 13:55:51 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	fsize;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	fsize = size - dlen - 1;
	i = 0;
	if (size <= dlen)
	{
		return (size + slen);
	}
	while (src[i] != '\0' && i < fsize)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
// #include <stdio.h>
// int main() {
//     char dest[11] = "Hello";
//     const char *source = " World";
//     size_t result = ft_strlcat(dest, source, 8);

//     printf("Resulting string: %s\n", dest);
//     printf("Total length of 'Hello World': %zu\n", result);

//     return (0);
// }