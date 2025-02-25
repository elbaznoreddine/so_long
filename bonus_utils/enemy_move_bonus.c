/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:40:34 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:06:39 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	try_enemy_move(t_game *game, int enemy_index,
		const int directions[4][2], int *dir_indices)
{
	int		j;
	t_pos	old;
	t_pos	new;

	old.x = game->map->enemy_x[enemy_index];
	old.y = game->map->enemy_y[enemy_index];
	j = 0;
	while (j < 4)
	{
		new.x = old.x + directions[dir_indices[j]][0];
		new.y = old.y + directions[dir_indices[j]][1];
		if (is_valid_move(game, new.x, new.y))
		{
			update_enemy_position(game, enemy_index, old, new);
			return (1);
		}
		j++;
	}
	return (0);
}

static void	init_dir_indices(int *dir_indices)
{
	dir_indices[0] = 0;
	dir_indices[1] = 1;
	dir_indices[2] = 2;
	dir_indices[3] = 3;
}

static int	process_enemy_movements(t_game *game,
		const int directions[4][2])
{
	int	moved;
	int	i;
	int	dir_indices[4];

	moved = 0;
	i = 0;
	while (i < game->map->m_count)
	{
		init_dir_indices(dir_indices);
		shuffle_directions(dir_indices);
		if (try_enemy_move(game, i, directions, dir_indices))
			moved = 1;
		i++;
	}
	return (moved);
}

void	move_enemy(t_game *game)
{
	static int			g_frame_counter = 0;
	static int			g_move_interval = 50;
	static const int	directions[4][2] = {{0, 1}, {1, 0},
	{0, -1}, {-1, 0}};
	int					moved;

	g_frame_counter++;
	if (g_frame_counter < g_move_interval)
		return ;
	g_frame_counter = 0;
	moved = process_enemy_movements(game, directions);
	if (!moved)
		write(STDERR_FILENO, "\a", 1);
}

int	game_loop(t_game *game)
{
	if (game->map->m_count > 0)
		move_enemy(game);
	render_game(game);
	return (0);
}
