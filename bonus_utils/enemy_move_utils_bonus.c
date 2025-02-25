/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:47:56 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:06:27 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_valid_move(t_game *game, int x, int y)
{
	return (x >= 0 && x < game->map->width && y >= 0 && y < game->map->height
		&& (game->map->grid[y][x] == '0' || game->map->grid[y][x] == 'P'));
}

void	update_enemy_position(t_game *game, int enemy_index,
	t_pos old, t_pos new)
{
	if (game->map->grid[new.y][new.x] == 'P')
	{
		ft_printf("Game Over\n");
		close_window(game);
	}
	game->map->grid[old.y][old.x] = '0';
	game->map->grid[new.y][new.x] = 'M';
	game->map->enemy_x[enemy_index] = new.x;
	game->map->enemy_y[enemy_index] = new.y;
}

void	shuffle_directions(int *dir_indices)
{
	int	j;
	int	k;
	int	temp;

	j = 3;
	while (j > 0)
	{
		k = rand() % (j + 1);
		temp = dir_indices[j];
		dir_indices[j] = dir_indices[k];
		dir_indices[k] = temp;
		j--;
	}
}
