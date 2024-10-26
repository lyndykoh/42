/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:56:25 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 15:24:28 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
		return (ch);
	}
	else
		return (ch);
}
// #include <stdio.h>
// int main(void)
// {
//     char c;

//     c = 'm';
//     printf("%c -> %c\n", c, ft_tolower(c));

//     c = 'D';
//     printf("%c -> %c\n", c, ft_tolower(c));

//     c = '9';
//     printf("%c -> %c\n", c, ft_tolower(c));
//     return (0);
// }