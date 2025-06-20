/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:31:42 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/21 01:15:01 by lkoh             ###   ########.fr       */
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
		printf("Usage: ./cub3d <mapfile.cub>\n");
		return (1);
	}

	t_map map = {0};

	read_file(&map, argv[1]);

	// Print parsed data
	printf("Parsed Textures:\n");
	printf("NO: %s", map.no_text);
	printf("SO: %s", map.so_text);
	printf("EA: %s", map.ea_text);
	printf("WE: %s", map.we_text);

	printf("\nParsed Floor RGB: %d,%d,%d\n",
		map.floor_rgb[0], map.floor_rgb[1], map.floor_rgb[2]);

	printf("Parsed Ceiling RGB: %d,%d,%d\n",
		map.ceiling_rgb[0], map.ceiling_rgb[1], map.ceiling_rgb[2]);

	// ✅ Print the map
	printf("\nParsed Map:\n");
	for (int i = 0; map.map && map.map[i]; i++)
		printf("%s", map.map[i]);  // newline already included from get_next_line


	return 0;
}
