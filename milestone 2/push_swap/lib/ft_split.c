/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:37 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/24 18:09:44 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
	{
		return (NULL);
	}
	i = 0;
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	freesplit(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		if (split[i])
		{
			free(split[i]);
		}
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	start;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			split[j] = word_dup(s, start, i);
			if (!split[j++])
				return (freesplit(split, j), NULL);
		}
		else
			i++;
	}
	return (split[j] = NULL, split);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	// Test string
	const char *test_string = "This is a test string for ft_split";

	// Test delimiter
	char delimiter = ' ';

	// Call ft_split
	char **result = ft_split(test_string, delimiter);

	// Output the result
	printf("Result of ft_split:\n");
	for (int i = 0; result[i] != NULL; ++i) {
		printf("%s\n", result[i]);
	}

	// Free memory
	for (int i = 0; result[i] != NULL; ++i) {
		free(result[i]);
	}
	free(result);

	return (0);
}*/
