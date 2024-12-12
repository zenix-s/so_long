/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_collected.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:00 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/shared/collectibles_shared.h"

t_bool	all_collected(t_game *game)
{
	if (game->player->score == game->collectibles->n_collectibles)
		return (TRUE);
	return (FALSE);
}
