/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:01:49 by serferna          #+#    #+#             */
/*   Updated: 2025/01/11 16:01:51 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLES_H

# define COLLECTIBLES_H

# include "../structs.h"

t_bool	all_collected(t_game *game);

void	collect_collectible(t_game *game, int32_t x, int32_t y);

t_bool	init_collectibles(t_game *game);

t_bool	render_collectibles(t_game *game);

void	free_collectibles(t_game *game);

#endif
