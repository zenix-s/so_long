#include "../../include/so_long.h"


t_bool	find_valid_path(t_game *game)
{
	t_dis_set	*dis_set;
	int32_t		y;
	int32_t		x;
	const int	directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int			i;
	int32_t		new_x;
	int32_t		new_y;
	t_dis_item	*root;

	if (!alloc_dis_set(&dis_set, game))
		return (FALSE);
	y = 0;
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x] == '1')
				continue ;
			// got for each direction and join the sets
			// if the direction is not null
			i = -1;
			while (++i < 4)
			{
				new_x = x + directions[i][0];
				new_y = y + directions[i][1];
				if (game->map->layout[new_y][new_x] == '1')
					continue ;
				union_dis_items(get_dis_item(dis_set, x, y),
					get_dis_item(dis_set, new_x, new_y));
			}
		}
		y++;
	}
	// Go from the start to the end and check if all Player,
	// Collectible and Exit have the same root
	// If they have the same root, then the path is valid
	// Else, the path is invalid
	y = 0;
	root = NULL;
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x] == '1')
				continue ;
			if (game->map->layout[y][x] == 'P' || game->map->layout[y][x] == 'C'
				|| game->map->layout[y][x] == 'E')
			{
				if (root == NULL)
					root = find_dis_item(get_dis_item(dis_set, x, y));
				else if (root != find_dis_item(get_dis_item(dis_set, x, y)))
				{
					// Cleanup
					// TODO: Implement cleanup
					return (FALSE);
				}
			}
		}
		y++;
	}
	return (TRUE);
}

t_bool	valid_map(t_game *game, t_map_info *map_info)
{
	if (!valid_n_items(map_info))
		return (FALSE);
	if (!check_border(game))
		return (FALSE);
	if (!find_valid_path(game))
		return (ft_error("Not all collectibles and exit are reachable"), FALSE);
	return (TRUE);
}
