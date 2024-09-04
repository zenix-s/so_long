/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:37 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_bool	valid_map(t_game *game, t_map_info *map_info)
{
	if (!valid_n_items(map_info))
		return (FALSE);
	if (!check_border(game))
		return (FALSE);
	if (!find_valid_path(game))
		return (ft_error("Not all collectibles and exit are reachable"), FALSE);
	return (TRUE);
}
