/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:37 by serferna          #+#    #+#             */
/*   Updated: 2024/12/07 12:55:41 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"
#include "../../../include/shared/shared.h"

t_bool	valid_map(t_game *game)
{
	if (!valid_n_items(game))
		return (FALSE);
	if (!check_border(game))
		return (FALSE);
	return (TRUE);
}

// Esto tendria que estar aparte sub modulo path validation
	// if (!find_valid_path(game))
	// 	return (ft_error("Not all collectibles and exit are reachable"), FALSE);
