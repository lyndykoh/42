/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:45 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 14:10:04 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
//#include <stdio.h>

//void	my_function(unsigned int index, char *c)
//{
//	index++;
//	index--;
//	// Check if the character is lowercase (ASCII value between 'a' and 'z').
//	if (*c >= 'a' && *c <= 'z')
//	{
//		*c = *c - 32;
//	}
//}
