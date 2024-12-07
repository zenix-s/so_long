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
#include "../../../include/shared/shared.h"

t_bool	check_border(t_game *game)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if ((y == 0 || y == game->map->height - 1)
				&& game->map->layout[y][x]->type != WALL)
				return (ft_error("Invalid map file_1"), FALSE);
			else if ((x == 0 || x == game->map->width - 1)
				&& game->map->layout[y][x]->type != WALL)
				return (ft_error("Invalid map file_2"), FALSE);
		}
	}
	return (TRUE);
}
