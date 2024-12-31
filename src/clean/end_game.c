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
	free_game(game);
	if (success)
	{
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
