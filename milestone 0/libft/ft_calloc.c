/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:49:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/03 13:49:39 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;

	result = malloc(nitems * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nitems * size);
	return (result);
}
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     // Example usage of my_calloc
//     int *array = ft_calloc(5, sizeof(int)); 
	// Allocate and zero an array of 5 integers

//     if (array != NULL) {
//         // Print the initialized values to confirm they are set to zero
//         for (int i = 0; i < 5; i++) {
//             printf("%d ", array[i]);
//         }
//         printf("\n");

//         // Free allocated memory
//         free(array);
//     } else {
//         printf("Memory allocation failed\n");
//     }

//     return (0);
// }
