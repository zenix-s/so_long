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
#include "../../include/shared.h"

static void	collect(t_game *game, int32_t index);

void	collect_collectible(t_game *game, int32_t x, int32_t y)
{
	int32_t	index;

	index = 0;
	while (index < (game->collectibles->n_collectibles))
	{
		if (game->collectibles->collectibles[index]->x == x
			&& game->collectibles->collectibles[index]->y == y
			&& game->collectibles->collectibles[index]->collected == FALSE)
		{
			collect(game, index);
			return ;
		}
		index++;
	}
}

static void	collect(t_game *game, int32_t index)
{
	game->collectibles->collectibles[index]->collected = TRUE;
	game->player->score++;
	mlx_delete_image(
		game->mlx,
		game->collectibles->collectibles[index]->img);
	game->collectibles->collectibles[index]->img = mlx_texture_to_image(
			game->mlx,
			game->collectibles->textures->collectible_open);
	mlx_image_to_window(
		game->mlx,
		game->collectibles->collectibles[index]->img,
		game->collectibles->collectibles[index]->x * TILE_SIZE,
		game->collectibles->collectibles[index]->y * TILE_SIZE);
	mlx_set_instance_depth(
		game->collectibles->collectibles[index]->img->instances,
		2);
}
