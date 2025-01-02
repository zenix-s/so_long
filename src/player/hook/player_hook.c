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

#include "../../../include/player/player.h"
#include "../../../include/shared.h"

static void	player_animation(t_game *game)
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
	mlx_image_to_window(
		game->mlx,
		game->player->img,
		game->player->x * TILE_SIZE,
		game->player->y * TILE_SIZE);
}

static double	calculate_player_time_move(void)
{
	return (TILE_SIZE / CHARACTER_SPEED);
}

void	ft_player_hook(t_game *game)
{
	double	current_time;
	double	delta_time;

	current_time = mlx_get_time();
	delta_time = current_time - game->last_time;
	game->last_time = current_time;
	game->time_accumulated += delta_time;
	game->player->player_time += delta_time;
	if (game->time_accumulated >= calculate_player_time_move())
	{
		if (ft_player_move(game))
		{
			update_moves_string(game);
			game->time_accumulated = 0;
		}
	}
	if (game->player->player_time >= 0.25)
	{
		player_animation(game);
		game->player->player_time = 0;
	}
}
