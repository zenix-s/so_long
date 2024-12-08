/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:40 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 18:20:58 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

// SHARED
# include "./shared.h"

// COLLECTIBLES
# include "./collectibles/collectibles.h"

// EXIT
# include "./exit/exit.h"

// MAP
# include "./map/map.h"

// PLAYER
# include "./player/player.h"

// UTILS
void	ft_error(char *msg);

// INIT STRUCTS
t_bool	init_mlx(t_game *game);
t_bool	init_game(t_game **game);
t_bool	init_tileset(t_game *game);

// RENDER
t_bool	render_tileset(t_game *game);

// TEXT MOVES
t_bool	update_moves_string(t_game *game);

// ARGUMENTS VALIDATION
t_bool	check_arguments(int argc, char **argv);

// IS TILESET TYPE

// PLAYER
void	print_layout(t_game *game);

// MAP VALIDATION

// END GAME (FREE STRUCTS)
void	end_game(t_game *game, t_bool success);
void	end_mlx(t_game *game);
void	free_tileset(t_game *game);

// HOOKS
void	ft_player_hook(t_game *game);

#endif
