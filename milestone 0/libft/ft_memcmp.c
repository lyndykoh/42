/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:10 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/04 13:32:53 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int main () {
//    char str1[15];
//    char str2[15];
//    int ret;

//    memcpy(str1, "abcdef", 6);
//    memcpy(str2, "FFFFFF", 6);

//    ret = ft_memcmp(str1, str2, 5);
//    printf("%i\n", ret);

//    // if(ret > 0) {
//    //    printf("str2 is less than str1");
//    // } else if(ret < 0) {
//    //    printf("str1 is less than str2");
//    // } else {
//    //    printf("str1 is equal to str2");
//    // }

//    return(0);
// }