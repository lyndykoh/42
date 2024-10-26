/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:12 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/15 10:41:13 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define CAT "assets/cat.xpm"
# define FISH "assets/fish.xpm"
# define FLOOR "assets/floor.xpm"
# define WALL "assets/wall.xpm"
# define EXIT "assets/exit.xpm"

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_SPACE 32
# define KEY_ESC 65307

# include "ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gfx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		x;
	int		y;
	void	*floor;
	void	*cat;
	void	*exit;
	void	*fish;
	void	*wall;
}			t_gfx;

typedef struct s_data
{
	char	**map;
	char	**mappy;
	int		exit;
	int		fish;
	int		cat_x;
	int		cat_y;
	int		mapw;
	int		maph;
	int		dir;
	int		x;
	int		y;
	int		tx;
	int		ty;
	int		cat_count;
	int		fish_count;
	int		exit_count;
	int		steps;
	int		tcat_count;
	int		tfish_count;
	int		texit_count;
	t_gfx	*mlx;
}			t_data;

enum
{
	MVUP = 1,
	MVDOWN = 2,
	MVLEFT = 3,
	MVRIGHT = 4,
	NOMOVE = 0
};

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

char		**ft_split(char const *s, char c);
int			ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
void		floodfill(t_data *game, int x, int y);
void		initgame(t_data *game);
void		read_file(t_data *game, char *filename);
void		intimlx(t_gfx *mlx, t_data *game);
void		setup_window(t_gfx *mlx, t_data *game);
int			checkwalls(t_data *game);
int			meow(t_data *game);
int			checkmap(t_data *game);
void		floodfill(t_data *game, int x, int y);
int			checkpath(t_data *game);
int			close_win(t_data *game);
void		cleanup(t_data *game);
void		cleanmap(t_data *game);

#endif