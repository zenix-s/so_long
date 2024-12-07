/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:58:42 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 23:52:10 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/player/player_private.h"
#include "../../../include/player/player.h"
#include "../../../include/so_long.h"

void	ft_player_hook(t_game *game)
{
	double	current_time;
	double	delta_time;
	double	time_per_move;

	current_time = mlx_get_time();
	delta_time = current_time - game->last_time;
	game->last_time = current_time;
	game->time_accumulated += delta_time;
	game->player->player_time += delta_time;
	time_per_move = TILE_SIZE / CHARACTER_SPEED;
	if (game->time_accumulated >= time_per_move)
	{
		if (ft_player_move(game))
		{
			update_moves_string(game);
			game->time_accumulated = 0;
		}
	}
	charge_player_animation(game);
}
