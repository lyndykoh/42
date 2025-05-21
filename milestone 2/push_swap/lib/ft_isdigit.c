/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:51:11 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/24 21:57:40 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
//     char c = '0';

//     if (isdigit(c) == 0)
//          printf("%c is not a digit.",c);
//     else
//          printf("%c is a digit.",c);

//     if (ft_isdigit(c) == 0)
//         printf("\n%c is not a digit", c);
//     else
//         printf("\n%c is a digit", c);
//     return (0);
// }
