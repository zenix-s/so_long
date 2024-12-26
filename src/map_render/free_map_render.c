/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/12/15 16:04:50 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map_reder/map_render.h"

static void	free_map_render_textures(t_game *game)
{
	if (game->tileset->textures != NULL)
	{
		mlx_delete_texture(game->tileset->textures->wall);
		mlx_delete_texture(game->tileset->textures->wall_1);
		mlx_delete_texture(game->tileset->textures->floor);
		mlx_delete_texture(game->tileset->textures->floor_1);
		mlx_delete_texture(game->tileset->textures->floor_2);
		free(game->tileset->textures);
	}
}

void	free_map_render(t_game *game)
{
	int32_t	i;

	if (game->tileset == NULL)
		return ;
	if (game->tileset->tiles != NULL)
	{
		i = -1;
		while (++i < game->tileset->n_tiles)
		{
			if (game->tileset->tiles[i] == NULL)
				continue ;
			if (game->tileset->tiles[i]->img != NULL)
			{
				mlx_delete_image(
					game->mlx,
					game->tileset->tiles[i]->img);
			}
			free(game->tileset->tiles[i]);
		}
		free(game->tileset->tiles);
	}
	free_map_render_textures(game);
	free(game->tileset);
}
