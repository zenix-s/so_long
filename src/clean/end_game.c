/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	end_game(t_game *game, t_bool success)
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
	if (success)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
