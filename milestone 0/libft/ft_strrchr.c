/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:00:46 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/04 14:00:47 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if ((char)c == 0)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
//#include <stdio.h>
//#include <string.h>

// int main () {
//   int len;
//   const char str[] = "https://www.tutorialspoint.com";
//   const char ch = 't';
//   char *ret;

//   ret = ft_strrchr(str, ch);

//   printf("String after |%c| is - |%s|\n", ch, ret);

//   return(0);
//}