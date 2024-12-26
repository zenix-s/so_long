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

#include "../../include/exit/exit.h"

void	free_exit(t_game *game)
{
	if (game->exit == NULL)
	{
		return ;
	}
	if (game->exit->img != NULL)
	{
		mlx_delete_image(game->mlx, game->exit->img);
	}
	if (game->exit->textures != NULL)
	{
		mlx_delete_texture(game->exit->textures->exit_open);
		mlx_delete_texture(game->exit->textures->exit_closed);
		free(game->exit->textures);
	}
	free(game->exit);
}
