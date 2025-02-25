/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clean_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:24:29 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:08:16 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->enemy_x)
		free(map->enemy_x);
	if (map->enemy_y)
		free(map->enemy_y);
	free(map);
}

int	cleanup(t_game *game)
{
	if (!game)
		return (1);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->exitopen)
		mlx_destroy_image(game->mlx, game->exitopen);
	if (game->empty)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map);
	return (0);
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
}
