/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:59 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 17:43:14 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/shared/map_shared.h"

t_bool	is_floor(const t_game *game, const int32_t x, const int32_t y)
{
	if (game->map->layout[y][x]->type == FLOOR
		|| game->map->layout[y][x]->type == COLLECTIBLE
		|| game->map->layout[y][x]->type == EXIT
		|| game->map->layout[y][x]->type == PLAYER)
	{
		return (TRUE);
	}
	return (FALSE);
}
