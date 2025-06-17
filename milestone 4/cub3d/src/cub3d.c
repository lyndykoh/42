/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:31:42 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/17 22:34:22 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_map(t_map *map) {
	free(map->no_text);
	free(map->so_text);
	free(map->ea_text);
	free(map->we_text);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <mapfile.cub>\n", argv[0]);
		return (1);
	}

	t_map map = {0}; // zero-initialize everything

	read_file(&map, argv[1]);

	// Print results
	printf("Parsed Textures:\n");
	printf("NO: %s", map.no_text);
	printf("SO: %s", map.so_text);
	printf("EA: %s", map.ea_text);
	printf("WE: %s", map.we_text);

	printf("\nParsed Floor RGB: %d,%d,%d\n",
		map.floor_rgb[0], map.floor_rgb[1], map.floor_rgb[2]);

	printf("Parsed Ceiling RGB: %d,%d,%d\n",
		map.ceiling_rgb[0], map.ceiling_rgb[1], map.ceiling_rgb[2]);

	// Clean up
	free_map(&map);
	return 0;
}
