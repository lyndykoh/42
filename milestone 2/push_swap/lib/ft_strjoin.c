/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:48 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/24 18:09:51 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
//#include <stdio.h>

//int	main(void)
//{
//	char *result;

//	// Test 1: Normal concatenation
//	result = ft_strjoin("Hello", ", World!");
//	printf("Test 1 - Join Result: '%s'\n", result);
//	free(result); // Clean up memory

//	// Test 2: Joining with an empty string
//	result = ft_strjoin("Hello", "");
//	printf("Test 2 - Join Result: '%s'\n", result);
//	free(result); // Clean up memory
//}