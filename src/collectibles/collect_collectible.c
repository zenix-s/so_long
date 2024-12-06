/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:02 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/collectibles/collectibles.h"
#include "../../include/so_long.h"

void	collect_collectible(t_game *game, int32_t x, int32_t y)
{
	int32_t	i;

	i = 0;
	while (i < (game->collectibles->n_collectibles))
	{
		if (game->collectibles->collectibles[i]->x == x
			&& game->collectibles->collectibles[i]->y == y
			&& game->collectibles->collectibles[i]->collected == FALSE)
		{
			game->collectibles->collectibles[i]->collected = TRUE;
			game->player->score++;
			mlx_delete_image(game->mlx,
				game->collectibles->collectibles[i]->img);
			game->collectibles->collectibles[i]->img = mlx_texture_to_image(game->mlx,
					game->collectibles->textures->collectible_open);
			mlx_image_to_window(game->mlx,
				game->collectibles->collectibles[i]->img,
				game->collectibles->collectibles[i]->x * TILE_SIZE,
				game->collectibles->collectibles[i]->y * TILE_SIZE);
			mlx_set_instance_depth(game->collectibles->collectibles[i]->img->instances,
				2);
			return ;
		}
		i++;
	}
}
