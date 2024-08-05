#include "../../../include/so_long.h"

t_bool	alloc_dis_item(t_dis_item **dis_item, int32_t x, int32_t y)
{
	*dis_item = malloc(sizeof(t_dis_item));
	if (*dis_item == NULL)
	{
		return (ft_error("Failed to allocate memory for dis_item"), FALSE);
	}
	(*dis_item)->parent = *dis_item;
	(*dis_item)->x = x;
	(*dis_item)->y = y;
	return (TRUE);
}

t_bool	alloc_dis_set_items(t_dis_set **dis_set, t_game *game)
{
	int32_t	i;
	int32_t	y;
	int32_t	x;

	i = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x] == '1')
				continue ;
			if (!alloc_dis_item(&(*dis_set)->items[i], x, y))
			{
				// Cleanup on failure
				// TODO: Implement cleanup
				return (FALSE);
			}
			i++;
		}
		y++;
	}
	return (TRUE);
}

t_bool	alloc_dis_set(t_dis_set **dis_set, t_game *game)
{
	int32_t	size;

	size = get_dis_set_size(game);
	*dis_set = malloc(sizeof(t_dis_set));
	if (*dis_set == NULL)
	{
		return (ft_error("Failed to allocate memory for dis_set"), FALSE);
	}
	(*dis_set)->items = malloc(sizeof(t_dis_item *) * size);
	if ((*dis_set)->items == NULL)
	{
		free(*dis_set);
		return (ft_error("Failed to allocate memory for dis_set items"), FALSE);
	}
	(*dis_set)->size = size;
	if (!alloc_dis_set_items(dis_set, game))
	{
		// Cleanup on failure
		// TODO: Implement cleanup
		return (FALSE);
	}
	return (TRUE);
}
