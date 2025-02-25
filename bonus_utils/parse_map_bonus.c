/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:43:42 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:08:06 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	first_pass(int fd, t_map *map, int *count_enemy)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	map->width = get_line_length(line);
	while (line)
	{
		if (!validate_line(line, map, count_enemy) || !is_valid_char(line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

static int	allocate_grid(t_map *map)
{
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	return (1);
}

static int	second_pass(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	return (1);
}

static int	allocate_enemy_arrays(t_map *map, int count_enemy)
{
	if (count_enemy == 0)
	{
		map->enemy_x = NULL;
		map->enemy_y = NULL;
		return (1);
	}
	map->enemy_x = malloc(sizeof(int) * count_enemy);
	map->enemy_y = malloc(sizeof(int) * count_enemy);
	if (!map->enemy_x || !map->enemy_y)
		return (0);
	return (1);
}

t_map	*parse_map(char *filename)
{
	t_map	*map;
	int		fd;
	int		count_enemy;

	count_enemy = 0;
	map = init_map();
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !first_pass(fd, map, &count_enemy))
		return (free_map(map), NULL);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !allocate_grid(map) || !second_pass(fd, map))
		return (free_map(map), NULL);
	close(fd);
	if (!allocate_enemy_arrays(map, count_enemy)
		|| !is_map_valid(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
