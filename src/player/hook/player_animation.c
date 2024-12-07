/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:14:11 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 23:52:26 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/player/player_private.h"
#include "../../../include/so_long.h"

void	charge_player_animation(t_game *game)
{
	if (game->player->player_time >= 0.25)
	{
		game->player->animation += 1;
		if (game->player->animation >= 4)
			game->player->animation = 0;
		mlx_delete_image(game->mlx, game->player->img);
		if (game->player->animation == 0)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->frame_1);
		else if (game->player->animation == 1)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->frame_2);
		else if (game->player->animation == 2)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->frame_3);
		else if (game->player->animation == 3)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->frame_4);
		mlx_image_to_window(game->mlx, game->player->img, game->player->x
			* TILE_SIZE, game->player->y * TILE_SIZE);
		game->player->player_time = 0;
	}
}
