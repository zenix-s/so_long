#include "../../../include/so_long.h"

size_t	get_dis_set_size(t_game *game)
{
	size_t	size;
	size_t	y;
	size_t	x;

	size = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x] != '1')
				size++;
		}
		y++;
	}
	return (size);
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
	// Find the root of the set
	while (root->parent != root)
		root = root->parent;
	// Optimize the path to the root
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

t_dis_item	*get_dis_item(t_dis_set *dis_set, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < dis_set->size)
	{
		if (dis_set->items[i]->x == x && dis_set->items[i]->y == y)
			return (dis_set->items[i]);
		i++;
	}
	return (NULL);
}
