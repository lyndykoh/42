/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/15 10:45:24 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_movement(int keycode, t_data *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->dir = MVUP;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->dir = MVDOWN;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		game->dir = MVLEFT;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->dir = MVRIGHT;
	else if (keycode == KEY_ESC)
		close_win(game);
	else
		return (0);
	return (0);
}

void	movecat(t_data *game, int newx, int newy, int mv)
{
	if (game->fish_count == 0 && game->map[newy][newx] == 'E')
		(ft_printf("YAYYYYY after %d steps!\n", ++game->steps), close_win(game));
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->cat, newx
		* 64, newy * 64);
	if (game->map[game->cat_y][game->cat_x] == 'E')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->exit,
			(game->cat_x) * 64, (game->cat_y) * 64);
	else
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->floor, (game->cat_x) * 64, (game->cat_y) * 64);
	if (game->dir == MVUP)
		game->cat_y -= 1;
	if (game->dir == MVDOWN)
		game->cat_y += 1;
	if (game->dir == MVLEFT)
		game->cat_x -= 1;
	if (game->dir == MVRIGHT)
		game->cat_x += 1;
	if (game->map[newy][newx] == 'C')
	{
		game->fish_count--;
		game->map[newy][newx] = '0';
		ft_printf("Fishies: %d\n", game->fish_count);
	}
	game->dir = NOMOVE;
}

int	animate(t_data *game)
{
	if (game->dir == MVUP && game->map[game->cat_y - 1][game->cat_x] != '1')
	{
		movecat(game, (game->cat_x), (game->cat_y - 1), MVUP);
		ft_printf("Steps: %d\n", ++game->steps);
	}
	if (game->dir == MVDOWN && game->map[game->cat_y + 1][game->cat_x] != '1')
	{
		movecat(game, (game->cat_x), (game->cat_y + 1), MVDOWN);
		ft_printf("Steps: %d\n", ++game->steps);
	}
	if (game->dir == MVLEFT && game->map[game->cat_y][game->cat_x - 1] != '1')
	{
		movecat(game, (game->cat_x - 1), (game->cat_y), MVLEFT);
		ft_printf("Steps: %d\n", ++game->steps);
	}
	if (game->dir == MVRIGHT && game->map[game->cat_y][game->cat_x + 1] != '1')
	{
		movecat(game, (game->cat_x + 1), (game->cat_y), MVRIGHT);
		ft_printf("Steps: %d\n", ++game->steps);
	}
}

void	gamestart(t_gfx *mlx, t_data *game)
{
	intimlx(mlx, game);
	setup_window(mlx, game);
	mlx_hook(mlx->win, ON_KEYDOWN, 1L << 0, key_movement, game);
	mlx_hook(mlx->win, ON_DESTROY, 1L << 0, close_win, game);
	mlx_loop_hook(mlx->mlx, animate, game);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	game;
	t_gfx	mlx;

	if (argc != 2)
		return (ft_printf("hello more lah\n"));
	initgame(&game);
	game.mlx = &mlx;
	read_file(&game, argv[1]);
	if (checkmap(&game) == -1)
	{
		cleanmap(&game);
		exit(1);
	}
	if (checkpath(&game) == -1)
	{
		cleanmap(&game);
		exit(1);
	}
	gamestart(&mlx, &game);
	cleanup(&game);
}
