/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:03:57 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/15 10:39:54 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_data *game)
{
	if (game->mlx->exit)
		mlx_destroy_image(game->mlx->mlx, game->mlx->exit);
	if (game->mlx->wall)
		mlx_destroy_image(game->mlx->mlx, game->mlx->wall);
	if (game->mlx->floor)
		mlx_destroy_image(game->mlx->mlx, game->mlx->floor);
	if (game->mlx->fish)
		mlx_destroy_image(game->mlx->mlx, game->mlx->fish);
	if (game->mlx->cat)
		mlx_destroy_image(game->mlx->mlx, game->mlx->cat);
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	cleanmap(game);
}

void	cleanmap(t_data *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		free(game->map[game->y]);
		game->y++;
	}
	free(game->map);
	game->y = -1;
	while (game->mappy[++game->y])
		free(game->mappy[game->y]);
	free(game->mappy);
}

int	close_win(t_data *game)
{
	cleanup(game);
	exit(0);
}
