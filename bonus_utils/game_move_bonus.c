/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:42:59 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:07:06 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	can_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map->width
		|| new_y < 0 || new_y >= game->map->height)
		return (0);
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[game->map->player_y][game->map->player_x] != 'E')
		game->map->grid[game->map->player_y][game->map->player_x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
}

static int	handle_game_end(t_game *game, char current_pos)
{
	if (current_pos == 'M')
	{
		ft_printf("Game over in %d moves!\n", game->moves);
		close_window(game);
		return (1);
	}
	if (current_pos == 'E' && game->map->c_count == 0)
	{
		ft_printf("You won in %d moves!\n", game->moves);
		close_window(game);
		return (1);
	}
	return (0);
}

int	move_player(t_game *game, int new_x, int new_y)
{
	char	current_pos;

	if (!can_move(game, new_x, new_y))
		return (0);
	current_pos = game->map->grid[new_y][new_x];
	if (current_pos == 'C')
		game->map->c_count--;
	update_player_position(game, new_x, new_y);
	if (current_pos != 'E')
		game->map->grid[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (handle_game_end(game, current_pos))
		return (1);
	render_game(game);
	return (1);
}

int	key_handler(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;
	if (keycode == 53)
		close_window(game);
	if (keycode == 13 || keycode == 126)
		new_y--;
	else if (keycode == 1 || keycode == 125)
		new_y++;
	else if (keycode == 0 || keycode == 123)
		new_x--;
	else if (keycode == 2 || keycode == 124)
		new_x++;
	else
		return (0);
	return (move_player(game, new_x, new_y));
}
