/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_floor_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:59 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_bool	is_floor_tile(int32_t x, int32_t y, t_game *game)
{
	if (game->map->layout[y][x] == '0' || game->map->layout[y][x] == 'C'
		|| game->map->layout[y][x] == 'E' || game->map->layout[y][x] == 'P')
		return (TRUE);
	return (FALSE);
}
