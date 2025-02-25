/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:24:12 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/02 21:58:11 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		p_count;
	int		e_count;
	int		c_count;
	int		m_count;
	int		*enemy_x;
	int		*enemy_y;
	int		player_x;
	int		player_y;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*collect;
	void	*enemy;
	void	*exit;
	void	*exitopen;
	void	*empty;
	t_map	*map;
	int		img_width;
	int		img_height;
	int		moves;
}				t_game;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_size
{
	int	width;
	int	height;
}				t_size;

typedef struct s_fill
{
	int	c_count;
	int	e_found;
}				t_fill;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

t_map	*parse_map(char *filename);
int		count_elements(t_map *map, int y, int x);
int		is_map_valid(t_map *map);
t_map	*init_map(void);
int		validate_line(char *line, t_map *map, int *count_enemy);
int		is_valid_char(char *line);
void	free_map(t_map *map);
int		get_line_length(char *line);
int		init_game(t_game *game);
void	put_img(t_game *game, char c, int x, int y);
void	render_game(t_game *game);
int		cleanup(t_game *game);
int		close_window(t_game *game);
int		can_move(t_game *game, int new_x, int new_y);
int		move_player(t_game *game, int new_x, int new_y);
int		key_handler(int keycode, t_game *game);
char	**copy_map(char **original, int height);
void	ft_flood_fill(char **map, t_point pos, t_fill *fill, t_size size);
int		validate_path(t_game *game);
void	free_map_copy(char **map, int height);
int		game_loop(t_game *game);
void	move_enemy(t_game *game);
int		is_valid_move(t_game *game, int x, int y);
void	update_enemy_position(t_game *game, int enemy_index,
			t_pos old, t_pos new);
void	shuffle_directions(int *dir_indices);
int		moves_print(t_game *game);

#endif