/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:02 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 17:43:22 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/shared/map_shared.h"

t_bool	is_wall(const t_game *game, const int32_t x, const int32_t y)
{
	if (game->map->layout[y][x]->type == WALL)
	{
		return (TRUE);
	}
	return (FALSE);
}
