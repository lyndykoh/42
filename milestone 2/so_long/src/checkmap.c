/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:03:57 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/15 10:39:46 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkwalls(t_data *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if ((game->y == 0) && (game->map[game->y][game->x] != '1'))
				return (ft_printf("ur top walls missing bro\n"), -1);
			if (game->x == 0 && (game->map[game->y][game->x] != '1'))
				return (ft_printf("ur left walls missing bro\n"), -1);
			if ((game->y == game->maph - 1)
				&& (game->map[game->y][game->x] != '1'))
				return (ft_printf("ur bottom walls missing bro\n %d  %d %c",
						game->y, game->x, game->map[game->y][game->x]), -1);
			if ((game->x == game->mapw - 1)
				&& (game->map[game->y][game->x] != '1'))
				return (ft_printf("ur right walls missing bro\n"), -1);
			game->x++;
		}
		game->y++;
	}
	return (0);
}

int	meow(t_data *game)
{
	if (game->map[game->y][game->x] == 'P')
	{
		game->cat_count++;
		game->cat_x = game->x;
		game->cat_y = game->y;
	}
	if (game->map[game->y][game->x] == 'C')
		game->fish_count++;
	if (game->map[game->y][game->x] == 'E')
		game->exit_count++;
	if (!ft_strchr("10PCE", game->map[game->y][game->x]))
		return (ft_printf("brother this map cmi lah\n"), -1);
	game->x++;
	return (0);
}

int	checkmap(t_data *game)
{
	game->y = 0;
	game->mapw = ft_strlen(game->map[0]);
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (meow(game) == -1)
				return (-1);
		}
		if (game->x != game->mapw)
			return (ft_printf("hello gimme retangle\n"), -1);
		game->y++;
	}
	game->maph = game->y;
	if (checkwalls(game) == -1)
		return (-1);
	if (game->cat_count != 1 || game->fish_count < 1 || game->exit_count != 1)
		return (ft_printf("brother this map cmi lah\n"), -1);
	else
		return (0);
}

void	floodfill(t_data *game, int x, int y)
{
	if (game->mappy[y][x] == '1' || game->mappy[y][x] == 'A')
		return ;
	if (game->mappy[y][x] == 'C')
		game->tfish_count++;
	if (game->mappy[y][x] == 'E')
		game->texit_count++;
	if (game->mappy[y][x] == 'P')
		game->tcat_count++;
	game->mappy[y][x] = 'A';
	floodfill(game, x + 1, y);
	floodfill(game, x - 1, y);
	floodfill(game, x, y + 1);
	floodfill(game, x, y - 1);
}

int	checkpath(t_data *game)
{
	floodfill(game, game->cat_x, game->cat_y);
	if (game->tfish_count != game->fish_count)
		return (ft_printf("cant catch fish bodoh\n"), -1);
	if (game->texit_count != game->exit_count)
		return (ft_printf("LET ME OUTT!!!!!\n"), -1);
	if (game->tcat_count != game->cat_count)
		return (ft_printf("HOW UW ME TO CATCH IF IM NOT AROUND\n"), -1);
	return (0);
}
