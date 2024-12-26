/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 20:54:36 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map.h"

void	free_map(t_game *game)
{
	int32_t	y;
	int32_t	x;

	if (game->map == NULL)
		return ;
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		if (game->map->layout[y] == NULL)
			continue ;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x] == NULL)
				continue ;
			free(game->map->layout[y][x]);
		}
		free(game->map->layout[y]);
	}
	free(game->map->layout);
	free(game->map->collectibles);
	free(game->map);
}
