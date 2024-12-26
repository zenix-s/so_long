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
#include "../../include/shared.h"

static t_bool	alloc_collectibles(t_game *game, int32_t n_collectibles)
{
	t_collectible	**collectibles;

	game->collectibles = malloc(sizeof(t_collectibles));
	if (game->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	collectibles = malloc(sizeof(t_collectible *) * n_collectibles);
	if (collectibles == NULL)
	{
		free(game->collectibles);
		game->collectibles = NULL;
		return (ft_error("Allocation failed for collectibles"), FALSE);
	}
	game->collectibles->collectibles = collectibles;
	game->collectibles->n_collectibles = n_collectibles;
	game->collectibles->textures = malloc(sizeof(t_collectible_texture));
	if (game->collectibles->textures == NULL)
	{
		free(game->collectibles->collectibles);
		free(game->collectibles);
		game->collectibles = NULL;
		return (ft_error("Allocation failed for collectibles textures"), FALSE);
	}
	return (TRUE);
}

static t_bool	init_collectible(
	t_collectible **collectible,
	int32_t x,
	int32_t y
)
{
	*collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (*collectible == NULL)
	{
		return (ft_error("Failed to allocate memory for collectible"), FALSE);
	}
	(*collectible)->x = x;
	(*collectible)->y = y;
	(*collectible)->collected = FALSE;
	return (TRUE);
}

static t_bool	load_collectibles_textures(t_game *game)
{
	game->collectibles->textures->collectible = mlx_load_png(COL_URL);
	if (game->collectibles->textures->collectible == NULL)
	{
		return (ft_error("Failed to load collectible texture"), FALSE);
	}
	game->collectibles->textures->collectible_open = mlx_load_png(COL_OPEN_URL);
	if (game->collectibles->textures->collectible_open == NULL)
	{
		mlx_delete_texture(game->collectibles->textures->collectible);
		return (ft_error("Failed to load collectible_open texture"), FALSE);
	}
	return (TRUE);
}

t_bool	init_collectibles(t_game *game)
{
	int32_t	i;

	if (!alloc_collectibles(game, game->map->n_collectibles))
		return (FALSE);
	if (!load_collectibles_textures(game))
		return (FALSE);
	i = -1;
	while (++i < game->map->n_collectibles)
	{
		if (!init_collectible(&game->collectibles->collectibles[i],
				game->map->collectibles[i]->x, game->map->collectibles[i]->y))
			return (FALSE);
	}
	return (TRUE);
}
