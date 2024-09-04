/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:52 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_collectibles_textures(t_game *game)
{
	if (game->collectibles->textures != NULL)
	{
		mlx_delete_texture(game->collectibles->textures->collectible);
		mlx_delete_texture(game->collectibles->textures->collectible_open);
		free(game->collectibles->textures);
	}
}

void	free_collectibles(t_game *game)
{
	int32_t	i;

	if (game->collectibles == NULL)
		return ;
	i = -1;
	while (++i < game->collectibles->n_collectibles)
	{
		if (game->collectibles->collectibles[i] == NULL)
			continue ;
		if (game->collectibles->collectibles[i]->img != NULL)
			mlx_delete_image(game->mlx,
				game->collectibles->collectibles[i]->img);
		free(game->collectibles->collectibles[i]);
	}
	free_collectibles_textures(game);
	free(game->collectibles->collectibles);
	free(game->collectibles);
}
