/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:41:48 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/17 22:52:28 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_map 
{
    char **map;
    char *no_text;
    char *so_text;
    char *ea_text;
    char *we_text;
    int floor_rgb[3];
    int ceiling_rgb[3];

} t_map;

void split_rgb(char *line, int *rgb);
void read_file(t_map *map, char *filename);

#endif