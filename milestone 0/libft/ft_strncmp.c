/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:56:13 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 13:56:14 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] == '\0' || str2[i] == '\0' || str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
//#include <stdio.h>
//#include <string.h>

// int main () {
//   char str1[15];
//   char str2[15];
//   int ret;

//   strcpy(str1, "abcdef");
//   strcpy(str2, "FEDCBA");

//   ret = ft_strncmp(str1, str2, 4);

//    printf("%i\n", ret);

//   return(0);
//}