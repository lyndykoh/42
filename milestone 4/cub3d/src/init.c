/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:47:44 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/17 22:54:14 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void split_rgb(char *line, int *rgb)
{
    int i;
    char **part;

    i = 0;
    part = ft_split(line, ',');
    while (i < 3)
    {
        rgb[i] = ft_atoi(part[i]);
        i++;
    }
    free(part);
}

void read_file(t_map *map, char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("cant open file\n");
        exit (0);
    }

    while ((line = get_next_line(fd)))
    {
        if (ft_strncmp(line, "NO ", 3) == 0)
            map->no_text = ft_strdup(line + 3);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            map->so_text = ft_strdup(line + 3);
        else if (ft_strncmp(line, "EA ", 3) == 0)
            map->ea_text = ft_strdup(line + 3);
        else if (ft_strncmp(line, "WE ", 3) == 0)
            map->we_text = ft_strdup(line + 3);
        else if(ft_strncmp(line, "F ", 2) == 0)
            split_rgb(line + 2, map->floor_rgb);
        else if(ft_strncmp(line, "C ", 2) == 0)
            split_rgb(line + 2, map->ceiling_rgb);
    }
} 