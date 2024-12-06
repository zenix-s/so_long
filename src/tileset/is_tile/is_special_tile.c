/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_special_tile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:00 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_bool	is_special_tile(const t_game *game, const int32_t x, const int32_t y)
{
	if (game->map->layout[y][x] == 'C' || game->map->layout[y][x] == 'P'
		|| game->map->layout[y][x] == 'E')
		return (TRUE);
	return (FALSE);
}
