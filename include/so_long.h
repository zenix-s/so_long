/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:40 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:41 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

// MLX42 LIB
# include "../lib/MLX42/include/MLX42/MLX42.h"
// LIBFT
# include "../lib/libft/libft.h"
// Malloc, free, exit
# include <stdlib.h>
// Close
# include <unistd.h>
// Open
# include <fcntl.h>
// NULL
# include <stdio.h>

// SHARED
# include "./shared/shared.h"

// STRUCTS
# include "./structs.h"

// EXIT
# include "./exit/exit.h"

// COLLECTIBLES
# include "./collectibles/collectibles.h"

# define TILE_SIZE 64
// Character Speed pixels per second
# define CHARACTER_SPEED 320.0
# define VALID_EXTENSION ".ber"

// UTILS
void		ft_error(char *msg);

// INIT STRUCTS
t_bool		init_mlx(t_game *game);
t_bool		init_game(t_game **game);
t_bool		init_map(t_game *game, char **file_path);
t_bool		init_tileset(t_game *game);
t_bool		init_player(t_game *game);
void		init_map_info(t_map_info *validate_map);

// RENDER
t_bool		render_tileset(t_game *game);
t_bool		render_player(t_game *game);

// TEXT MOVES
t_bool		update_moves_string(t_game *game);

// ARGUMENTS VALIDATION
t_bool		check_arguments(int argc, char **argv);

// IS TILESET TYPE
t_bool		is_floor_tile(const t_game *game, const int32_t x, const int32_t y);
t_bool		is_collectible_tile(const t_game *game, const int32_t x,
				const int32_t y);
t_bool		is_exit_tile(const t_game *game, const int32_t x, const int32_t y);
t_bool		is_special_tile(const t_game *game, const int32_t x,
				const int32_t y);
t_bool		is_wall_tile(const t_game *game, const int32_t x, const int32_t y);

// PLAYER
t_bool		ft_player_move(t_game *game);

void		print_layout(t_game *game);

// MAP VALIDATION
t_bool		valid_map(t_game *game, t_map_info *validate_map);
t_bool		check_border(t_game *game);
t_bool		valid_n_items(t_map_info *validate_map);
t_bool		find_valid_path(t_game *game);
t_bool		check_line(t_game *game, char *line, t_map_info *validate_map);

// DISJOINT SET
t_bool		alloc_dis_item(t_dis_item **dis_item, int32_t x, int32_t y);
t_bool		alloc_dis_set_items(t_dis_set **dis_set, t_game *game);
t_bool		alloc_dis_set(t_dis_set **dis_set, t_game *game);
int32_t		get_dis_set_size(t_game *game);
t_dis_item	*find_dis_item(t_dis_item *item);
t_dis_item	*get_dis_item(t_dis_set *dis_set, int32_t x, int32_t y);
void		union_dis_items(t_dis_item *item1, t_dis_item *item2);
void		free_dis_set(t_dis_set *dis_set);

// END GAME (FREE STRUCTS)
void		end_game(t_game *game, t_bool success);
void		end_mlx(t_game *game);
void		free_map(t_game *game);
void		free_player(t_game *game);
void		free_tileset(t_game *game);

// HOOKS
void		ft_player_hook(t_game *game);

#endif
