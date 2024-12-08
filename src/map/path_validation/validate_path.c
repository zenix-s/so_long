/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:20 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 15:08:07 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"

/**
 * Find the root of the set
 * Optimize the path to the root
 * @param item
 * @return t_dis_item* --> root
 */
static t_map_node_item	*get_parent(t_map_node_item *item)
{
	t_map_node_item	*root;

	root = item;
	while (root->parent != root)
		root = root->parent;
	while (item->parent != root)
		item->parent = root;
	return (root);
}

static void	union_items(t_map_node_item *item1, t_map_node_item *item2)
{
	t_map_node_item	*root1;
	t_map_node_item	*root2;

	root1 = get_parent(item1);
	root2 = get_parent(item2);
	if (root1 != root2)
		root2->parent = root1;
}

static void	generate_tree(t_game *game)
{
	static const int	dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int32_t				y;
	int32_t				x;
	int					i;

	y = 0;
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x]->type == WALL)
				continue ;
			i = -1;
			while (++i < 4)
			{
				if (game->map->layout[y + dir[i][1]][x
					+ dir[i][0]]->type == WALL)
					continue ;
				union_items(game->map->layout[y][x], game->map->layout[y
					+ dir[i][1]][x + dir[i][0]]);
			}
		}
		y++;
	}
}

static t_bool	check_parents(t_game *game)
{
	int32_t			i;
	t_map_node_item	*root;

	root = get_parent(game->map->player);
	if (root->x != get_parent(game->map->exit)->x
		|| root->y != get_parent(game->map->exit)->y)
		return (FALSE);
	i = game->map->n_collectibles;
	while (--i >= 0)
	{
		if (root->x != get_parent(game->map->collectibles[i])->x
			|| root->y != get_parent(game->map->collectibles[i])->y)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	valid_path(t_game *game)
{
	generate_tree(game);
	if (!check_parents(game))
		return (ft_error("Unreachable exit or collectible"), FALSE);
	return (TRUE);
}
