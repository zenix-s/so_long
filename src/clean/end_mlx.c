/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	end_mlx(t_game *game)
{
	if (game->mlx == NULL)
	{
		return ;
	}
	mlx_terminate(game->mlx);
	game->mlx = NULL;
}
