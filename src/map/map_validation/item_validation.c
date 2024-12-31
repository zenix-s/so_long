/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:47:36 by serferna          #+#    #+#             */
/*   Updated: 2024/12/07 23:14:44 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"

static t_bool	validate_player(t_game *game, t_map_node_item *item)
{
	if (game->map->player != NULL)
	{
		return (ft_error("Player must appear exactly once"), FALSE);
	}
	game->map->player = item;
	return (TRUE);
}

static t_bool	validate_exit(t_game *game, t_map_node_item *item)
{
	if (game->map->exit != NULL)
	{
		return (ft_error("Exit must appear exactly once"), FALSE);
	}
	game->map->exit = item;
	return (TRUE);
}

static t_bool	realloc_collectible(t_game *game, t_map_node_item *item)
{
	t_map_node_item	**new_collectibles;
	int32_t			i;

	new_collectibles = (t_map_node_item **)malloc(sizeof(t_map_node_item *)
			* (game->map->n_collectibles + 1));
	if (new_collectibles == NULL)
	{
		free(item);
		return (ft_error("Failed to allocate memory for collectible"), FALSE);
	}
	i = -1;
	while (++i < game->map->n_collectibles)
	{
		new_collectibles[i] = game->map->collectibles[i];
	}
	new_collectibles[i] = item;
	if (game->map->collectibles != NULL)
	{
		free(game->map->collectibles);
	}
	game->map->collectibles = new_collectibles;
	game->map->n_collectibles++;
	return (TRUE);
}

t_bool	validate_item(t_game *game, t_map_node_item *item)
{
	if (item->type == PLAYER && !validate_player(game, item))
	{
		return (FALSE);
	}
	if (item->type == EXIT && !validate_exit(game, item))
	{
		return (FALSE);
	}
	if (item->type == COLLECTIBLE && !realloc_collectible(game, item))
	{
		return (FALSE);
	}
	return (TRUE);
}
