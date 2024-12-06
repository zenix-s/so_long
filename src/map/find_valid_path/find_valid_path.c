/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:20 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"
#include "../../../include/so_long.h"

static void	create_tree(t_game *game, t_dis_set *dis_set)
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
			if (game->map->layout[y][x] == '1')
				continue ;
			i = -1;
			while (++i < 4)
			{
				if (game->map->layout[y + dir[i][1]][x + dir[i][0]] == '1')
					continue ;
				union_dis_items(get_dis_item(dis_set, x, y),
					get_dis_item(dis_set, x + dir[i][0], y + dir[i][1]));
			}
		}
		y++;
	}
}

static t_bool	check_roots(t_game *game, t_dis_set *dis_set)
{
	int32_t		y;
	int32_t		x;
	t_dis_item	*root;

	y = 0;
	root = NULL;
	while (y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (is_wall_tile(game, x, y))
				continue ;
			if (is_special_tile(game, x, y))
			{
				if (root == NULL)
					root = find_dis_item(get_dis_item(dis_set, x, y));
				else if (root != find_dis_item(get_dis_item(dis_set, x, y)))
					return (FALSE);
			}
		}
		y++;
	}
	return (TRUE);
}

t_bool	find_valid_path(t_game *game)
{
	t_dis_set	*dis_set;

	if (!alloc_dis_set(&dis_set, game))
		return (FALSE);
	create_tree(game, dis_set);
	if (!check_roots(game, dis_set))
	{
		free_dis_set(dis_set);
		return (ft_error("Invalid map file_3"), FALSE);
	}
	free_dis_set(dis_set);
	return (TRUE);
}
