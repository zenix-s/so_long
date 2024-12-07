/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:54:02 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 23:06:55 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H

# define PLAYER_H

# include "../../include/shared/shared.h"
# include "../structs.h"

t_bool	init_player(t_game *game);

t_bool	ft_player_move(t_game *game);

t_bool	render_player(t_game *game);

void	free_player(t_game *game);

#endif
