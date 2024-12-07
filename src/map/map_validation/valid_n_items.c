/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_n_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:28 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"
#include "../../../include/shared/shared.h"

t_bool	valid_n_items(t_game *game)
{
	if (game->map->player == NULL)
		return (ft_error("Player not found"), FALSE);
	if (game->map->exit == NULL)
		return (ft_error("Exit not found"), FALSE);
	if (game->map->n_collectibles == 0)
		return (ft_error("Collectible not found"), FALSE);
	return (TRUE);
}
