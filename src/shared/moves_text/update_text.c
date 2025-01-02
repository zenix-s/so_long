/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:41 by serferna          #+#    #+#             */
/*   Updated: 2025/01/02 15:12:28 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/shared.h"

t_bool	update_moves_string(t_game *game)
{
	char	*moves_str;
	char	*moves;

	if (game->movement != NULL)
	{
		mlx_delete_image(game->mlx, game->movement);
	}
	moves = ft_itoa(game->player->moves);
	if (moves == NULL)
	{
		ft_error("Failed to allocate memory for moves string");
		return (FALSE);
	}
	moves_str = ft_strjoin("Moves: ", moves);
	free(moves);
	if (moves_str == NULL)
	{
		ft_error("Failed to allocate memory for moves string");
		return (FALSE);
	}
	game->movement = mlx_put_string(game->mlx, (const char *)moves_str, 10, 10);
	free(moves_str);
	return (TRUE);
}
