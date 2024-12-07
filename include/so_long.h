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

// Malloc, free, exit
# include <stdlib.h>
// Close
# include <unistd.h>
// Open
# include <fcntl.h>
// NULL
# include <stdio.h>

// MLX42 LIB
# include "../lib/MLX42/include/MLX42/MLX42.h"

// LIBFT
# include "../lib/libft/libft.h"

// SHARED
# include "./shared/shared.h"

// STRUCTS
# include "./structs.h"

// COLLECTIBLES
# include "./collectibles/collectibles.h"

// EXIT
# include "./exit/exit.h"

// MAP
# include "./map/map.h"

// PLAYER
# include "./player/player.h"

# define TILE_SIZE 64
// Character Speed pixels per second
# define CHARACTER_SPEED 320.0
# define VALID_EXTENSION ".ber"

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
t_bool	is_floor_tile(const t_game *game, const int32_t x, const int32_t y);
t_bool	is_collectible_tile(const t_game *game, const int32_t x,
			const int32_t y);
t_bool	is_exit_tile(const t_game *game, const int32_t x, const int32_t y);
t_bool	is_special_tile(const t_game *game, const int32_t x, const int32_t y);
t_bool	is_wall_tile(const t_game *game, const int32_t x, const int32_t y);

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
