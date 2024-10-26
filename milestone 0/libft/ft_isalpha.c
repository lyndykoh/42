/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:50:40 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/04 17:15:39 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char c = 'R';

//     if (isalpha(c) == 0)
//          printf("test %c is not an alphabet.", c);
//     else
//          printf("test %c is an alphabet.", c);

//     if (ft_isalpha(c) == 0)
//         printf("\n%c is not an alpha", c);
//     else
//         printf("\n%c is an alpha", c);

//     return (0);
// }
