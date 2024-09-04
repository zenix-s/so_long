/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tileset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:06 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_bool	render_floor(t_game *game, int32_t i);
static t_bool	render_wall(t_game *game, int32_t i);

t_bool	render_tileset(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < game->tileset->n_tiles)
	{
		if (game->tileset->tiles[i]->type == '0')
			render_floor(game, i);
		else if (game->tileset->tiles[i]->type == '1')
			render_wall(game, i);
		if (mlx_image_to_window(game->mlx, game->tileset->tiles[i]->img,
				game->tileset->tiles[i]->x * TILE_SIZE,
				game->tileset->tiles[i]->y * TILE_SIZE) == -1)
			return (ft_error("Failed to render tile image"), FALSE);
		mlx_set_instance_depth(game->tileset->tiles[i]->img->instances, 1);
		i++;
	}
	return (TRUE);
}

static t_bool	render_floor(t_game *game, int32_t i)
{
	unsigned int	rand;

	rand = gen_rand(1, 4, &game->rand_seed);
	if (rand == 1)
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->floor_2);
	else if (rand == 2)
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->floor_1);
	else
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->floor);
	return (TRUE);
}

static t_bool	render_wall(t_game *game, int32_t i)
{
	if ((game->tileset->tiles[i]->y + 1) == game->map->height)
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->wall_1);
	else if (!is_wall_tile(game->tileset->tiles[i]->x,
			game->tileset->tiles[i]->y + 1, game))
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->wall_1);
	else
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->wall);
	return (TRUE);
}
