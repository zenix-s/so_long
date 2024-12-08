/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:04 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/collectibles/collectibles.h"
#include "../../include/so_long.h"

static t_bool	alloc_collectibles(t_game *game, int32_t n_collectibles)
{
	t_collectible	**collectibles;

	game->collectibles = (t_collectibles *)malloc(sizeof(t_collectibles));
	if (game->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	collectibles = (t_collectible **)malloc(sizeof(t_collectible *)
			* n_collectibles);
	game->collectibles->collectibles = collectibles;
	if (game->collectibles->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	game->collectibles->n_collectibles = n_collectibles;
	game->collectibles->textures = (t_collectible_texture *)malloc(sizeof(t_collectible_texture));
	if (game->collectibles->textures == NULL)
		return (ft_error("Failed to allocate memory for collectibles textures"),
			FALSE);
	return (TRUE);
}

static int32_t	get_number_collectibles(t_game *game)
{
	int32_t	x;
	int32_t	y;
	int32_t	n_collectibles;

	n_collectibles = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->layout[y][x]->type == COLLECTIBLE)
				n_collectibles++;
			x++;
		}
		y++;
	}
	return (n_collectibles);
}

static t_bool	init_collectible(t_collectible **collectible, int32_t x,
		int32_t y)
{
	*collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (*collectible == NULL)
		return (ft_error("Failed to allocate memory for collectible"), FALSE);
	(*collectible)->x = x;
	(*collectible)->y = y;
	(*collectible)->collected = FALSE;
	return (TRUE);
}

static t_bool	load_collectibles_textures(t_game *game)
{
	game->collectibles->textures->collectible = mlx_load_png("textures/collectible.png");
	if (game->collectibles->textures->collectible == NULL)
		return (ft_error("Failed to load collectible texture"), FALSE);
	game->collectibles->textures->collectible_open = mlx_load_png("textures/collectible_open.png");
	if (game->collectibles->textures->collectible_open == NULL)
		return (ft_error("Failed to load collectible_open texture"), FALSE);
	return (TRUE);
}

t_bool	init_collectibles(t_game *game)
{
	int32_t	x;
	int32_t	y;
	int32_t	i;

	if (!alloc_collectibles(game, get_number_collectibles(game)))
		return (FALSE);
	if (!load_collectibles_textures(game))
		return (FALSE);
	i = 0;
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (!is_collectible(game, x, y))
				continue ;
			if (!init_collectible(&game->collectibles->collectibles[i], x, y))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}
