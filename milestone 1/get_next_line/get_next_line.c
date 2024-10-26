/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:59:00 by lkoh              #+#    #+#             */
/*   Updated: 2024/08/29 22:02:20 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*readline(int fd, char *buffer, char *backup)
{
	int		check;
	int		i;
	char	*temp;

	check = 1;
	if (!backup)
		backup = ft_strdup("");
	while (check)
	{
		i = 0;
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			break ;
		buffer[check] = '\0';
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		while (backup[i])
		{
			if (backup[i] == '\n')
				return (backup);
			i++;
		}
	}
	return (backup);
}

char	*yappayappa(char **line)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	if (!(*line)[i])
		return (NULL);
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	temp = ft_substr(*line, 0, i + 1);
	if (!temp)
		return (NULL);
	if (!temp[0])
	{
		free(temp);
		return (NULL);
	}
	temp2 = ft_substr(*line, i + 1, ft_strlen(*line) - i);
	free(*line);
	*line = temp2;
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*backup;
	char		*buff;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	backup = NULL;
	line = readline(fd, buff, line);
	free(buff);
	if (!line)
		return (NULL);
	backup = yappayappa(&line);
	if (!backup)
	{
		free(line);
		line = NULL;
	}
	return (backup);
}

//#include <stdio.h>
//#include <stdlib.h>

//// Assuming get_next_line is already defined elsewhere
// char *get_next_line(int fd);

// int main(void)
//{
//	FILE *file = fopen("gnlTester/files/multiple_line_no_nl", "r");
//	if (file == NULL) {
//		perror("Failed to open file");
//		return (EXIT_FAILURE);
//	}

//	int fd = fileno(file);
//	char *line;

//	while ((line = get_next_line(fd)) != NULL) {
//			printf("%s", line);
//		free(line);
//	}
//	fclose(file);
//	return (EXIT_SUCCESS);
//}

#include <fcntl.h>
#include <stdio.h>
int gnl(int fd)
{
    char    *s;
    s = get_next_line(fd);
    printf("%s", s);
    if (s)
    {
        free(s);
        s = NULL;
        return (1);
    }
    return (0);
}
int main(void)
{
    int fd1;
    int state1;
    // int fd2;
    // int fd3;
    // int state2;
    // int state3;
    fd1 = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
    // fd2 = open("file1", O_RDONLY);
    // fd3 = open("file2", O_RDONLY);
    state1 = 1;
    // state2 = 2;
    // state3 = 3;
    while (state1)
    {
        state1 = gnl(fd1);
        // state2 = gnl(fd2);
        // state3 = gnl(fd3);
        // printf("\n");
    }
    close(fd1);
    return (0);
}