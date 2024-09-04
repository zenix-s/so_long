/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_player(t_game *game)
{
	if (game->player == NULL)
		return ;
	if (game->player->img != NULL)
		mlx_delete_image(game->mlx, game->player->img);
	if (game->player->textures != NULL)
	{
		mlx_delete_texture(game->player->textures->player);
		mlx_delete_texture(game->player->textures->player_1);
		mlx_delete_texture(game->player->textures->player_2);
		mlx_delete_texture(game->player->textures->player_3);
		free(game->player->textures);
	}
	free(game->player);
}
