/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tileset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:04 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_bool	alloc_tileset(t_game *game)
{
	int32_t	width;
	int32_t	height;

	width = game->map->width;
	height = game->map->height;
	game->tileset = (t_tileset *)malloc(sizeof(t_tileset));
	if (game->tileset == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	game->tileset->tiles = (t_tile **)malloc(sizeof(t_tile *) * width * height);
	game->tileset->n_tiles = 0;
	if (game->tileset->tiles == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	game->tileset->textures = (t_tile_texture *)malloc(sizeof(t_tile_texture));
	if (game->tileset->textures == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	return (TRUE);
}

static t_bool	init_tile(t_tile **tile, int32_t x, int32_t y, t_game *game)
{
	*tile = (t_tile *)malloc(sizeof(t_tile));
	if (*tile == NULL)
		return (ft_error("Failed to allocate memory for tile"), FALSE);
	(*tile)->img = NULL;
	if (is_floor(game, x, y))
		(*tile)->type = '0';
	else if (is_wall(game, x, y))
		(*tile)->type = '1';
	return (true);
}

static t_bool	load_tile_textures(t_game *game)
{
	game->tileset->textures->wall = mlx_load_png("textures/wall.png");
	if (game->tileset->textures->wall == NULL)
		return (ft_error("Failed to load wall texture"), FALSE);
	game->tileset->textures->wall_1 = mlx_load_png("textures/wall_1.png");
	if (game->tileset->textures->wall_1 == NULL)
		return (ft_error("Failed to load wall texture"), FALSE);
	game->tileset->textures->floor = mlx_load_png("textures/floor.png");
	if (game->tileset->textures->floor == NULL)
		return (ft_error("Failed to load floor texture"), FALSE);
	game->tileset->textures->floor_1 = mlx_load_png("textures/floor_1.png");
	if (game->tileset->textures->floor_1 == NULL)
		return (ft_error("Failed to load floor texture"), FALSE);
	game->tileset->textures->floor_2 = mlx_load_png("textures/floor_2.png");
	if (game->tileset->textures->floor_2 == NULL)
		return (ft_error("Failed to load floor texture"), FALSE);
	return (TRUE);
}

t_bool	init_tileset(t_game *game)
{
	int32_t	x;
	int32_t	y;

	if (!alloc_tileset(game))
		return (FALSE);
	if (!load_tile_textures(game))
		return (FALSE);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			init_tile(&game->tileset->tiles[y * game->map->width + x], x, y,
				game);
			game->tileset->tiles[y * game->map->width + x]->x = x;
			game->tileset->tiles[y * game->map->width + x]->y = y;
			x++;
		}
		y++;
	}
	game->tileset->n_tiles = game->map->height * game->map->width;
	return (TRUE);
}
