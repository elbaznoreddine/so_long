/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:59:14 by noel-baz          #+#    #+#             */
/*   Updated: 2025/01/23 03:42:21 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_copy(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **original, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	ft_flood_fill(char **map, t_point pos, t_fill *fill, t_size size)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= size.width || pos.y >= size.height)
		return ;
	if (!map[pos.y] || map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'F')
		return ;
	if (map[pos.y][pos.x] == 'C')
		(fill->c_count)--;
	if (map[pos.y][pos.x] == 'E')
		fill->e_found = 1;
	map[pos.y][pos.x] = 'F';
	ft_flood_fill(map, (t_point){pos.x + 1, pos.y}, fill, size);
	ft_flood_fill(map, (t_point){pos.x - 1, pos.y}, fill, size);
	ft_flood_fill(map, (t_point){pos.x, pos.y + 1}, fill, size);
	ft_flood_fill(map, (t_point){pos.x, pos.y - 1}, fill, size);
}

static char	**ft_validate_map_structure(t_game *game)
{
	if (!game->map || !game->map->grid || game->map->height <= 0
		|| game->map->width <= 0)
	{
		ft_printf("Error: Invalid map structure\n");
		return (NULL);
	}
	return (copy_map(game->map->grid, game->map->height));
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	t_fill	fill;
	t_point	pos;

	fill.c_count = game->map->c_count;
	fill.e_found = 0;
	pos.x = game->map->player_x;
	pos.y = game->map->player_y;
	map_copy = ft_validate_map_structure(game);
	if (!map_copy)
	{
		ft_printf("Error: Failed to allocate memory for map copy\n");
		return (-1);
	}
	ft_flood_fill(map_copy, pos, &fill,
		(t_size){game->map->width, game->map->height});
	free_map_copy(map_copy, game->map->height);
	return (fill.c_count == 0 && fill.e_found);
}
