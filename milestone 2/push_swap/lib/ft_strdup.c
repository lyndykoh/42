/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:43 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/24 18:09:49 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	int		srclen;
	int		i;
	char	*dest;

	srclen = ft_strlen(s);
	dest = malloc(sizeof(char) * (srclen + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < srclen)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char source[] = "GeeksForGeeks";

//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target = ft_strdup(source);

//     printf("%s", target);
//     return (0);
// }