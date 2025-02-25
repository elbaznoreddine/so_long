/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:00:47 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:07:58 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	count_elements(t_map *map, int y, int x)
{
	if (map->grid[y][x] == 'P')
	{
		map->p_count++;
		map->player_x = x;
		map->player_y = y;
	}
	else if (map->grid[y][x] == 'E')
		map->e_count++;
	else if (map->grid[y][x] == 'C')
		map->c_count++;
	else if (map->grid[y][x] == 'M')
	{
		map->enemy_x[map->m_count] = x;
		map->enemy_y[map->m_count] = y;
		map->m_count++;
	}
	else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
		return (0);
	return (1);
}

int	is_map_valid(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
			{
				if (map->grid[y][x] != '1')
					return (0);
			}
			if (!count_elements(map, y, x))
				return (0);
		}
	}
	return (map->p_count == 1 && map->e_count == 1
		&& map->c_count >= 1 && map->m_count >= 0);
}

int	is_valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P' && line[i] != 'M' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->m_count = 0;
	map->enemy_x = NULL;
	map->enemy_y = NULL;
	return (map);
}

int	validate_line(char *line, t_map *map, int *count_enemy)
{
	if (get_line_length(line) != map->width)
		return (0);
	map->height++;
	if (ft_strchr(line, 'M'))
		(*count_enemy)++;
	return (1);
}
