/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:14 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_bool	render_closed_exit(t_game *game)
{
	game->exit->img = mlx_texture_to_image(game->mlx,
			game->exit->textures->exit_closed);
	if (game->exit->img == NULL)
	{
		return (ft_error("Failed to create exit image"), FALSE);
	}
	if (mlx_image_to_window(game->mlx, game->exit->img, game->exit->x
	                                                    * TILE_SIZE, game->exit->y * TILE_SIZE) == -1)
	{
		return (ft_error("Failed to render exit image"), FALSE);
	}
	mlx_set_instance_depth(game->exit->img->instances, 2);
	return (TRUE);
}
