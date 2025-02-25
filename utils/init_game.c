/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:44:54 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/02 22:30:39 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_game(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	game->moves = 0;
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./imgs/player.xpm", &game->img_width, &game->img_height);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./imgs/collect.xpm", &game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit.xpm", &game->img_width, &game->img_height);
	game->exitopen = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit1.xpm", &game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./imgs/wall.xpm", &game->img_width, &game->img_height);
	game->empty = mlx_xpm_file_to_image(game->mlx,
			"./imgs/earth.xpm", &game->img_width, &game->img_height);
	if (!game->player || !game->collect || !game->exit
		|| !game->wall || !game->empty || !game->exitopen)
	{
		return (0);
	}
	return (1);
}

void	put_img(t_game *game, char c, int x, int y)
{
	x *= game->img_width;
	y *= game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, game->empty, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
}

static void	ft_handle_exit_tile(t_game *game, int x, int y)
{
	if (game->map->player_x == x && game->map->player_y == y
		&& game->map->c_count > 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * game->img_width, y * game->img_height);
	}
	else if (game->map->c_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exitopen, x * game->img_width,
			y * game->img_height);
	}
}

static void	ft_render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map->grid[y][x];
	put_img(game, tile, x, y);
	if (tile == 'E')
		ft_handle_exit_tile(game, x, y);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
