/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:41:18 by serferna          #+#    #+#             */
/*   Updated: 2024/12/26 23:45:02 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	free_exit(game);
	free_player(game);
	free_collectibles(game);
	free_map(game);
	free_map_render(game);
	if (game->movement != NULL)
		mlx_delete_image(game->mlx, game->movement);
	end_mlx(game);
	if (game != NULL)
		free(game);
}
