/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:37 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 00:13:35 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"

t_bool	valid_map(t_game *game)
{
	if (!valid_items(game))
		return (FALSE);
	if (!check_border(game))
		return (FALSE);
	return (TRUE);
}
