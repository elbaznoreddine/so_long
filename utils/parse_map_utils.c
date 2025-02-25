/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:45:21 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/04 00:49:09 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
		return (0);
	return (1);
}

int	get_line_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] && line[length] != '\n')
		length++;
	return (length);
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
	return (map->p_count == 1 && map->e_count == 1 && map->c_count >= 1);
}

int	is_valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_dimensions(t_map *map, int fd)
{
	char	*line;
	int		first_width;

	line = get_next_line(fd);
	if (!line)
		return (0);
	first_width = get_line_length(line);
	map->width = first_width;
	while (line)
	{
		if (get_line_length(line) != first_width || !is_valid_char(line))
		{
			free(line);
			return (0);
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
