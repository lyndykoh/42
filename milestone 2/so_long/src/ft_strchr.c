/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:41 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/04 14:46:19 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
//#include <stdio.h>
// int main(void)
//{
//    const char *str = "hello world";
//    char ch = 'w';
//    char *found = ft_strchr(str,ch);
//    if (found != NULL)
//    {
//        printf("%c, %ld\n", ch, found - str);
//    }
//    else
//    {
//        printf("not found\n");
//    }
//    return (0);
//}