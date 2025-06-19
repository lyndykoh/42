/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:47:44 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/19 11:18:12 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void initgame(t_map *map)
{
    map->map = NULL;
    map->no_text = NULL;
    map->so_text = NULL;
    map->ea_text = NULL;
    map->we_text = NULL;
    map->floor_rgb[0] = 0;
    map->floor_rgb[1] = 0;
    map->floor_rgb[2] = 0;
    map->ceiling_rgb[0] = 0;
    map->ceiling_rgb[1] = 0;
    map->ceiling_rgb[2] = 0;
    map->f = 0;
    map->c = 0;
}

void split_rgb(char *line, int *rgb)
{
    int i;
    char **part;

    i = 0;
    part = ft_split(line, ',');
    while (part[i])
    {
        if ((i < 3) && (ft_isstrnum(part[i])))
        {
            rgb[i] = ft_atoi(part[i]);
        }
        if (!ft_isstrnum(part[i]))
            break;
        i++;
    }
    if (i != 3)
    {
        perror("ur rgb like nice ah\n");
        exit(0);
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
        check_texture(map, line);
    }
    if (map->no_text == NULL || map->so_text == NULL || map->ea_text == NULL || map->we_text == NULL)
    {
        perror("ur map not correct sister.. missing smth\n");
        exit(0);
    }
    if (map->f == 0 || map->c == 0)
    {
        perror("sdjfladsj\n");
        exit(0);
    }
} 

void check_texture(t_map *map, char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0 && map->no_text == NULL)
        map->no_text = ft_strdup(line + 3);
    else if (ft_strncmp(line, "SO ", 3) == 0 && map->so_text == NULL)
        map->so_text = ft_strdup(line + 3);
    else if (ft_strncmp(line, "EA ", 3) == 0 && map->ea_text == NULL)
        map->ea_text = ft_strdup(line + 3);
    else if (ft_strncmp(line, "WE ", 3) == 0 && map->we_text == NULL)
        map->we_text = ft_strdup(line + 3);
    else if(map->f != 1 && (ft_strncmp(line, "F ", 2) == 0))
    {
        map->f = 1;
        split_rgb(line + 2, map->floor_rgb);
    }
    else if((ft_strncmp(line, "C ", 2) == 0))
    {
        map->c = 1;
        split_rgb(line + 2, map->ceiling_rgb);
    }
    else 
    {
        perror("eh wrong leh, got duplicate or smth missing\n");
        exit(0);
    }
}

int ft_isstrnum(char *line)
{
	int i;

    i=0;
	while (line[i])
	{
        if ((line[i] == '\n') && (i > 0))
            return (1);
		if ((line[i] < '0') || (line[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}