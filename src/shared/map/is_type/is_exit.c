/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:57 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 17:43:10 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/shared/map_shared.h"

t_bool	is_exit(const t_game *game, const int32_t x, const int32_t y)
{
	if (game->map->layout[y][x]->type == EXIT)
	{
		return (TRUE);
	}
	return (FALSE);
}
