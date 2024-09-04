/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tileset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_tileset_textures(t_game *game)
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

void	free_tileset(t_game *game)
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
				mlx_delete_image(game->mlx, game->tileset->tiles[i]->img);
			free(game->tileset->tiles[i]);
		}
		free(game->tileset->tiles);
	}
	free_tileset_textures(game);
	free(game->tileset);
}
