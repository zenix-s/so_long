/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:10 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 15:53:18 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exit/exit.h"
#include "../../include/shared.h"

static t_bool	alloc_exit(t_game *game)
{
	game->exit = malloc(sizeof(t_exit));
	if (game->exit == NULL)
	{
		return (ft_error("Failed to allocate memory for exit"), FALSE);
	}
	game->exit->open = FALSE;
	game->exit->textures = (t_exit_texture *)malloc(sizeof(t_exit_texture));
	if (game->exit->textures == NULL)
	{
		return (ft_error("Failed to allocate memory for exit textures"), FALSE);
	}
	return (TRUE);
}

static void	find_exit(t_game *game)
{
	t_map_node_item	*item;

	item = game->map->exit;
	game->exit->x = item->x;
	game->exit->y = item->y;
}

static t_bool	load_exit_textures(t_game *game)
{
	game->exit->textures->exit_closed
		= mlx_load_png("textures/exit_closed.png");
	if (game->exit->textures->exit_closed == NULL)
	{
		return (ft_error("Failed to load exit texture"), FALSE);
	}
	game->exit->textures->exit_open = mlx_load_png("textures/exit_open.png");
	if (game->exit->textures->exit_open == NULL)
	{
		return (ft_error("Failed to load exit texture"), FALSE);
	}
	return (TRUE);
}

t_bool	init_exit(t_game *game)
{
	if (!alloc_exit(game))
	{
		return (FALSE);
	}
	if (!load_exit_textures(game))
	{
		return (FALSE);
	}
	find_exit(game);
	return (TRUE);
}
