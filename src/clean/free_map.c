/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(t_game *game)
{
	int32_t	i;

	if (game->map == NULL)
		return ;
	i = -1;
	while (++i < game->map->height)
	{
		if (game->map->layout[i] == NULL)
			continue ;
		free(game->map->layout[i]);
	}
	free(game->map->layout);
	free(game->map);
}
