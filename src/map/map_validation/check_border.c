/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:26 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"
#include "../../../include/shared.h"

t_bool	check_border(t_game *game)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < game->map->height)
	{
		if (y == 0 || y == game->map->height - 1)
		{
			x = -1;
			while (++x < game->map->width)
			{
				if (!is_wall(game, x, y))
					return (ft_error("Map is not surrounded by walls"), FALSE);
			}
		}
		else if (!is_wall(game, 0, y) || !is_wall(game, game->map->width - 1,
				y))
			return (ft_error("Map is not surrounded by walls"), FALSE);
	}
	return (TRUE);
}
