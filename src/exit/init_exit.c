/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:10 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_bool	alloc_exit(t_game *game)
{
	game->exit = malloc(sizeof(t_exit));
	if (game->exit == NULL)
		return (ft_error("Failed to allocate memory for exit"), FALSE);
	game->exit->open = FALSE;
	game->exit->textures = (t_exit_texture *)malloc(sizeof(t_exit_texture));
	if (game->exit->textures == NULL)
		return (ft_error("Failed to allocate memory for exit textures"), FALSE);
	return (TRUE);
}

static void	find_exit(t_game *game)
{
	int32_t	y;
	int32_t	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (is_exit_tile(game, x, y))
			{
				game->exit->x = x;
				game->exit->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static t_bool	load_exit_textures(t_game *game)
{
	game->exit->textures->exit_closed = mlx_load_png("textures/exit_closed.png");
	if (game->exit->textures->exit_closed == NULL)
		return (ft_error("Failed to load exit texture"), FALSE);
	game->exit->textures->exit_open = mlx_load_png("textures/exit_open.png");
	if (game->exit->textures->exit_open == NULL)
		return (ft_error("Failed to load exit texture"), FALSE);
	return (TRUE);
}

t_bool	init_exit(t_game *game)
{
	if (!alloc_exit(game))
		return (FALSE);
	if (!load_exit_textures(game))
		return (FALSE);
	find_exit(game);
	return (TRUE);
}
