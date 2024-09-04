/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:26 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	init_game(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (*game == NULL)
		return (ft_error("Failed to allocate memory for game\n"), FALSE);
	(*game)->mlx = NULL;
	(*game)->map = NULL;
	(*game)->tileset = NULL;
	(*game)->collectibles = NULL;
	(*game)->player = NULL;
	(*game)->exit = NULL;
	(*game)->movement = NULL;
	(*game)->time_accumulated = 0.0;
	(*game)->last_time = 0.0;
	(*game)->rand_seed = 123456789;
	return (TRUE);
}
