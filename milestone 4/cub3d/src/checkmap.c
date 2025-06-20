/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:28:54 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/21 01:24:17 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ismap(char *line)
{
    int i;
    int dir;

    i = 0;
    dir = 0;
    while (line[i])
    {
        printf("-------- %s\n", line);
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
            dir++;
        else if (line[i] != '1' && line[i] != '0' && !ft_isspace(line[i]))
        {
            perror("ur map also wrong uw do what cub3d?\n");
            return (-1);
        }
        i++;
    }
    if (dir != 1)
    {
        perror("This one not multiplayer leh\n");
        return (-1);
    }
    printf("-------- %s\n", line);
    return (0);
}

void storemap(t_map *map, char *line)
{
    static char *map_content;
    char *temp;
    
    if (!is_map_line(line))
        return;
    if (!map_content)
        map_content = ft_strdup("");
    temp = map_content;
    map_content = ft_strjoin(map_content, line);
    free(temp);
    map->map = ft_split(map_content, '\n');
    map->mapfill = ft_split(map_content, '\n');
}

int is_map_line(char *line)
{
    int i;
    
    i = 0;
    while (ft_isspace(line[i]))
        i++;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && 
            line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && 
            line[i] != ' ' && line[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

