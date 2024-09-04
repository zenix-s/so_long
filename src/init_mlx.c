/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:14 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	init_mlx(t_game *game)
{
	int32_t	width;
	int32_t	height;
	int32_t	n1;
	int32_t	n2;

	width = game->map->width * TILE_SIZE;
	height = game->map->height * TILE_SIZE;
	game->mlx = mlx_init(width, height, "so_long", FALSE);
	if (game->mlx == NULL)
		return (ft_error("Failed to initialize mlx"), FALSE);
	mlx_get_monitor_size(0, &n1, &n2);
	if (width > n1 || height > n2)
		return (ft_error("Map is too big for the screen"), FALSE);
	return (true);
}
