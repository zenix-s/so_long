/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:18 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"

int32_t	get_dis_set_size(t_game *game)
{
	return (game->map->height * game->map->width);
}

/**
 * Find the root of the set
 * Optimize the path to the root
 * @param item
 * @return t_dis_item* --> root
 */
t_dis_item	*find_dis_item(t_dis_item *item)
{
	t_dis_item	*root;

	root = item;
	while (root->parent != root)
		root = root->parent;
	while (item->parent != root)
		item->parent = root;
	return (root);
}

void	union_dis_items(t_dis_item *item1, t_dis_item *item2)
{
	t_dis_item	*root1;
	t_dis_item	*root2;

	root1 = find_dis_item(item1);
	root2 = find_dis_item(item2);
	if (root1 != root2)
		root2->parent = root1;
}

t_dis_item	*get_dis_item(t_dis_set *dis_set, int32_t x, int32_t y)
{
	int32_t	i;

	i = 0;
	while (i < dis_set->size)
	{
		if (dis_set->items[i]->x == x && dis_set->items[i]->y == y)
			return (dis_set->items[i]);
		i++;
	}
	return (NULL);
}
