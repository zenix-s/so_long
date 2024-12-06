/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:44 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_bool	alloc_player(t_game *game)
{
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		return (ft_error("Failed to allocate memory for player"), FALSE);
	game->player->textures = (t_player_texture *)malloc(sizeof(t_player_texture));
	if (game->player->textures == NULL)
		return (ft_error("Failed to allocate memory for player"), FALSE);
	return (TRUE);
}

static t_bool	load_player_textures(t_game *game)
{
	game->player->textures->frame_1 = mlx_load_png("textures/player.png");
	if (game->player->textures->frame_1 == NULL)
		return (ft_error("Failed to load player texture"), FALSE);
	game->player->textures->frame_2 = mlx_load_png("textures/player_1.png");
	if (game->player->textures->frame_2 == NULL)
		return (ft_error("Failed to load player texture"), FALSE);
	game->player->textures->frame_3 = mlx_load_png("textures/player_2.png");
	if (game->player->textures->frame_3 == NULL)
		return (ft_error("Failed to load player texture"), FALSE);
	game->player->textures->frame_4 = mlx_load_png("textures/player_3.png");
	if (game->player->textures->frame_4 == NULL)
		return (ft_error("Failed to load player texture"), FALSE);
	return (TRUE);
}

static t_bool	find_player(t_game *game, int32_t *x, int32_t *y)
{
	*y = 0;
	*x = 0;
	while (*y < game->map->height)
	{
		*x = 0;
		while (*x < game->map->width)
		{
			if (game->map->layout[*y][*x] == 'P')
				return (TRUE);
			(*x)++;
		}
		(*y)++;
	}
	return (FALSE);
}

t_bool	init_player(t_game *game)
{
	int32_t	x;
	int32_t	y;

	if (!alloc_player(game))
		return (FALSE);
	if (!find_player(game, &x, &y))
		return (ft_error("Player starting position not found"), FALSE);
	if (!load_player_textures(game))
		return (FALSE);
	game->player->x = x;
	game->player->y = y;
	game->player->moves = 0;
	game->player->score = 0;
	game->player->animation = 0;
	game->player->player_time = 0.0;
	return (TRUE);
}
