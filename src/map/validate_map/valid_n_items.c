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

#include "../../../include/so_long.h"

t_bool	valid_n_items(t_map_info *map_info)
{
	if (!map_info->player)
		return (ft_error("Player not found"), FALSE);
	if (!map_info->exit)
		return (ft_error("Exit not found"), FALSE);
	if (!map_info->collectible)
		return (ft_error("Collectible not found"), FALSE);
	return (TRUE);
}
