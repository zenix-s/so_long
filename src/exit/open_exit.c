/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:12 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_bool	open_exit(t_game *game)
{
	if (game->exit->img != NULL)
	{
		mlx_delete_image(game->mlx, game->exit->img);
	}
	game->exit->img = mlx_texture_to_image(game->mlx,
	                                       game->exit->textures->exit_open);
	if (game->exit->img == NULL)
	{
		return (ft_error("Failed to create exit image"), FALSE);
	}
	mlx_image_to_window(game->mlx, game->exit->img, game->exit->x * TILE_SIZE,
	                    game->exit->y * TILE_SIZE);
	mlx_set_instance_depth(game->exit->img->instances, 2);
	game->exit->open = TRUE;
	return (TRUE);
}
