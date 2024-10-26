/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:25:58 by tsechen           #+#    #+#             */
/*   Updated: 2024/10/15 15:22:27 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*read_line(int fd, char *buffer, char **stash)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (*stash && ft_strchr(*stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (!*stash)
			*stash = ft_strdup("");
		temp = *stash;
		*stash = ft_strjoin(temp, buffer);
		free(temp);
		if (!*stash)
			return (NULL);
	}
	return (*stash);
}

static char	*get_line(char *line, char **stash)
{
	char	*temp;
	size_t	len;

	len = 0;
	while ((*stash)[len] != '\0' && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	line = ft_substr(*stash, 0, len);
	if (!line)
		return (NULL);
	temp = *stash;
	if ((*stash)[len] == '\0')
		*stash = NULL;
	else
	{
		*stash = ft_strdup(*stash + len);
		if (!*stash)
			return (free(temp), free(line), NULL);
	}
	return (free(temp), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash[fd] = read_line(fd, buffer, &stash[fd]);
	free(buffer);
	if (!stash[fd] || *stash[fd] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = get_line(line, &stash[fd]);
	return (line);
}
