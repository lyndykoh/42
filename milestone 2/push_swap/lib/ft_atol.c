/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:49:08 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/27 18:42:45 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}
/* #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 int main () {
	int val;
	char str[20];

	strcpy(str, "-98993489");
	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);

	strcpy(str, "tutorialspoint.com");
	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);

	return(0);
 }*/
