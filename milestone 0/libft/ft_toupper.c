/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:56:28 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 15:24:37 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
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
//     printf("%c -> %c\n", c, ft_toupper(c));

//     c = 'D';
//     printf("%c -> %c\n", c, ft_toupper(c));

//     c = '9';
//     printf("%c -> %c\n", c, ft_toupper(c));
//     return (0);
// }