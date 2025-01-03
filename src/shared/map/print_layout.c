/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:16 by serferna          #+#    #+#             */
/*   Updated: 2024/12/15 15:50:03 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/shared/map_shared.h"

void	print_layout(t_game *game)
{
	int32_t	y;
	int32_t	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_printf("%c", game->map->layout[y][x]->type);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
