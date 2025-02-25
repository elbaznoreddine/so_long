/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:25:22 by noel-baz          #+#    #+#             */
/*   Updated: 2025/01/23 03:23:44 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_allocate_grid(t_map *map, int fd)
{
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		close(fd);
		return (0);
	}
	return (1);
}

static int	ft_fill_grid(t_map *map, int fd)
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

static t_map	*ft_handle_map_error(t_map *map, int fd)
{
	if (map)
		free_map(map);
	if (fd >= 0)
		close(fd);
	return (NULL);
}

static t_map	*ft_process_map_content(t_map *map, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !ft_allocate_grid(map, fd))
		return (free(map), NULL);
	if (!ft_fill_grid(map, fd))
	{
		close(fd);
		return (free_map(map), NULL);
	}
	close(fd);
	if (!is_map_valid(map))
		return (free_map(map), NULL);
	return (map);
}

t_map	*parse_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !ft_check_dimensions(map, fd))
		return (ft_handle_map_error(map, fd));
	close(fd);
	return (ft_process_map_content(map, filename));
}
