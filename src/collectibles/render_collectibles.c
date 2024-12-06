/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:05 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/collectibles/collectibles.h"
#include "../../include/so_long.h"

t_bool	render_collectibles(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < game->collectibles->n_collectibles)
	{
		game->collectibles->collectibles[i]->img = mlx_texture_to_image(game->mlx,
				game->collectibles->textures->collectible);
		if (mlx_image_to_window(game->mlx,
				game->collectibles->collectibles[i]->img,
				game->collectibles->collectibles[i]->x * TILE_SIZE,
				game->collectibles->collectibles[i]->y * TILE_SIZE) == -1)
			return (ft_error("Failed to render collectible image"), FALSE);
		mlx_set_instance_depth(game->collectibles->collectibles[i]->img->instances,
			2);
		i++;
	}
	return (TRUE);
}
