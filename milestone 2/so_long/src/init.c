/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:03:57 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/15 10:10:34 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initgame(t_data *game)
{
	game->map = NULL;
	game->mappy = NULL;
	game->exit = 0;
	game->fish = 0;
	game->cat_x = 0;
	game->cat_y = 0;
	game->mapw = 0;
	game->maph = 0;
	game->dir = NOMOVE;
	game->x = 0;
	game->y = 0;
	game->cat_count = 0;
	game->fish_count = 0;
	game->exit_count = 0;
	game->steps = 0;
	game->tcat_count = 0;
	game->tfish_count = 0;
	game->texit_count = 0;
}

void	read_file(t_data *game, char *filename)
{
	int		fd;
	int		check;
	char	buffer[2500];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("aku cannot open file bodoh\n");
		exit(0);
	}
	check = read(fd, buffer, 2499);
	if (check == -1)
		ft_printf("i want to sing\n");
	if (check > 2400)
		ft_printf("wtf you gimme you fker\n");
	buffer[check] = '\0';
	game->map = ft_split(buffer, '\n');
	game->mappy = ft_split(buffer, '\n');
}

void	intimlx(t_gfx *mlx, t_data *game)
{
	mlx->width = game->mapw * 64;
	mlx->height = game->maph * 64;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_printf("Failed to initialize MLX");
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height,
			"MeowMeowMeowMeow");
	if (!mlx->win)
	{
		free(mlx->mlx);
		ft_printf("Failed to initialize MLX Window");
	}
	mlx->cat = mlx_xpm_file_to_image((mlx->mlx), CAT, &(mlx)->x, &(mlx)->y);
	mlx->fish = mlx_xpm_file_to_image((mlx->mlx), FISH, &(mlx)->x, &(mlx)->y);
	mlx->floor = mlx_xpm_file_to_image((mlx->mlx), FLOOR, &(mlx)->x, &(mlx)->y);
	mlx->wall = mlx_xpm_file_to_image((mlx->mlx), WALL, &(mlx)->x, &(mlx)->y);
	mlx->exit = mlx_xpm_file_to_image((mlx->mlx), EXIT, &(mlx)->x, &(mlx)->y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->fish, 0, 0);
}

void	setup_window(t_gfx *mlx, t_data *game)
{
	game->x = 0;
	while (game->x < game->mapw)
	{
		game->y = 0;
		while (game->y < game->maph)
		{
			if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->fish, game->x
					* 64, game->y * 64);
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, game->x
					* 64, game->y * 64);
			else if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cat, game->x
					* 64, game->y * 64);
			else if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, game->x
					* 64, game->y * 64);
			else if (game->map[game->y][game->x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor, game->x
					* 64, game->y * 64);
			game->y++;
		}
		game->x++;
	}
}
