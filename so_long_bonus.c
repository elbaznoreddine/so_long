/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:41:19 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 15:07:25 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_line_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] && line[length] != '\n')
		length++;
	return (length);
}

static int	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./so_long [map.ber]\n");
		return (1);
	}
	len = ft_strlen(av[1]) - 4;
	if (ft_strncmp(av[1] + len, ".ber", 4) != 0)
	{
		ft_printf("Error\nMap file must have .ber extension\n%s", av[1] + len);
		return (1);
	}
	return (0);
}

static int	init_game_structs(t_game *game, char *filename, int pixel)
{
	game->map = parse_map(filename);
	if (!game->map)
	{
		free(game);
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	if (game->map->height * pixel > 1312)
	{
		free_map(game->map);
		free(game);
		ft_printf("Error\nwindow reached max size\n");
		return (0);
	}
	if (!validate_path(game))
	{
		free_map(game->map);
		free(game);
		ft_printf("Error\nInvalid path\n");
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	return (1);
}

static int	init_and_check_game(t_game *game, int pixel)
{
	game->win = mlx_new_window(game->mlx,
			game->map->width * pixel,
			game->map->height * pixel, "so_long_bonus");
	if (!game->win)
	{
		cleanup(game);
		return (0);
	}
	if (!init_game(game))
	{
		perror("Error\ntexture file not found");
		cleanup(game);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		pixel;

	if (check_args(ac, av))
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	pixel = 32;
	if (!init_game_structs(game, av[1], pixel))
		return (1);
	if (!init_and_check_game(game, pixel))
		return (1);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 0, key_handler, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}
