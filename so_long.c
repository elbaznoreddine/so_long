/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:25:00 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 14:32:33 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_args(int ac, char *filename)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./so_long [map.ber]\n");
		return (0);
	}
	len = ft_strlen(filename) - 4;
	if (ft_strncmp(filename + len, ".ber", 4) != 0)
	{
		ft_printf("Error\nMap file must have .ber extension\n");
		return (0);
	}
	return (1);
}

static int	ft_init_window(t_game *game, int pixel)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map->width * pixel,
			game->map->height * pixel, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

static int	ft_setup_game(t_game *game, char *mapfile, int pixel)
{
	game->map = parse_map(mapfile);
	if (!game->map)
	{
		ft_printf("Error\nInvarlid map\n");
		free(game);
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
	return (1);
}

static void	ft_setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 0, key_handler, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	render_game(game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		pixel;

	if (!ft_check_args(ac, av[1]))
		return (1);
	pixel = 32;
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (!ft_setup_game(game, av[1], pixel))
		return (1);
	if (!ft_init_window(game, pixel))
	{
		cleanup(game);
		return (1);
	}
	if (!init_game(game))
	{
		perror("Error\ntexture file not found");
		return (1);
	}
	ft_setup_hooks(game);
	cleanup(game);
	return (0);
}
