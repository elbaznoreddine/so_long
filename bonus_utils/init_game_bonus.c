/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:43:07 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:07:45 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	init_game(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	game->moves = 0;
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./imgs/player.xpm", &game->img_width, &game->img_height);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./imgs/collect.xpm", &game->img_width, &game->img_height);
	if (game->map->m_count > 0)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"./imgs/enemy.xpm", &game->img_width, &game->img_height);
	else
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"./imgs/earth.xpm", &game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit.xpm", &game->img_width, &game->img_height);
	game->exitopen = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit1.xpm", &game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./imgs/wall.xpm", &game->img_width, &game->img_height);
	game->empty = mlx_xpm_file_to_image(game->mlx,
			"./imgs/earth.xpm", &game->img_width, &game->img_height);
	if (!game->player || !game->collect || !game->exit
		|| !game->wall || !game->empty || !game->enemy || !game->exitopen)
		return (0);
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
		mlx_put_image_to_window(game->collect, game->win, game->collect, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
	else if (c == 'M' && game->map->m_count > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
}

static void	render_exit_tile(t_game *game, int x, int y)
{
	if (game->map->player_x == x && game->map->player_y == y
		&& game->map->c_count > 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * game->img_width, y * game->img_height);
	}
	else if (game->map->c_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exitopen,
			x * game->img_width, y * game->img_height);
	}
}

int	moves_print(t_game *game)
{
	char	*str_moves;
	char	*num_str;

	num_str = ft_itoa(game->moves);
	str_moves = ft_strjoin("Moves: ", num_str);
	if (!str_moves)
		return (0);
	if (!mlx_string_put(game->mlx, game->win, 30, 10, 0xFFFFFF, str_moves))
	{
		free(str_moves);
		free(num_str);
		return (0);
	}
	free(num_str);
	free(str_moves);
	return (1);
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
			put_img(game, game->map->grid[y][x], x, y);
			if (game->map->grid[y][x] == 'E')
				render_exit_tile(game, x, y);
			x++;
		}
		y++;
	}
	if (!moves_print(game))
		return ;
}
