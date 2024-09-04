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
# include <stdio.h>

# define TILE_SIZE 64
// Character Speed pixels per second
# define CHARACTER_SPEED 320.0
# define VALID_EXTENSION ".ber"

// PLAYER RELATED
typedef struct s_player_texture
{
	mlx_texture_t			*player;
	mlx_texture_t			*player_1;
	mlx_texture_t			*player_2;
	mlx_texture_t			*player_3;
}							t_player_texture;

typedef struct s_player
{
	int32_t					score;
	int						moves;
	mlx_image_t				*img;
	int32_t					x;
	int32_t					y;
	int						moving;
	int						animation;
	double					player_time;
	t_player_texture		*textures;
}							t_player;

// EXIT RELATED
typedef struct s_exit_texture
{
	mlx_texture_t			*exit_open;
	mlx_texture_t			*exit_closed;
}							t_exit_texture;

typedef struct s_exit
{
	int32_t					x;
	int32_t					y;
	mlx_image_t				*img;
	t_bool					open;
	t_exit_texture			*textures;
}							t_exit;

// TILE RELATED
typedef struct s_tile
{
	int32_t					x;
	int32_t					y;
	mlx_image_t				*img;
	char					type;
}							t_tile;

typedef struct s_tile_texture
{
	mlx_texture_t			*wall;
	mlx_texture_t			*wall_1;
	mlx_texture_t			*floor;
	mlx_texture_t			*floor_1;
	mlx_texture_t			*floor_2;
}							t_tile_texture;

typedef struct s_tileset
{
	t_tile					**tiles;
	int32_t					n_tiles;
	t_tile_texture			*textures;
}							t_tileset;

// COLLECTIBLES RELATED
typedef struct s_collectible
{
	int32_t					x;
	int32_t					y;
	mlx_image_t				*img;
	t_bool					collected;
}							t_collectible;

typedef struct s_collectible_texture
{
	mlx_texture_t			*collectible;
	mlx_texture_t			*collectible_open;
}							t_collectible_texture;

typedef struct s_collectibles
{
	int32_t					n_collectibles;
	t_collectible			**collectibles;
	t_collectible_texture	*textures;
}							t_collectibles;

// MAP RELATED
typedef struct s_map
{
	int32_t					width;
	int32_t					height;
	char					**layout;
}							t_map;

typedef struct s_map_info
{
	t_bool					player;
	t_bool					exit;
	t_bool					collectible;
}							t_map_info;

// DISJOINT SET (FOR MAP VALIDATION)
typedef struct s_dis_item
{
	struct s_dis_item		*parent;
	int32_t					x;
	int32_t					y;
}							t_dis_item;

typedef struct s_dis_set
{
	t_dis_item				**items;
	int32_t					size;
}							t_dis_set;

// GAME PRINCIPAL STRUCT
typedef struct s_game
{
	mlx_t					*mlx;
	t_player				*player;
	t_map					*map;
	t_tileset				*tileset;
	t_collectibles			*collectibles;
	t_exit					*exit;
	double					last_time;
	double					time_accumulated;
	mlx_image_t				*movement;
	unsigned int			rand_seed;
}							t_game;

// UTILS
void						ft_error(char *msg);
unsigned int				gen_rand(unsigned int min, unsigned int max,
								unsigned int *seed);

// INIT STRUCTS
t_bool						init_mlx(t_game *game);
t_bool						init_game(t_game **game);
t_bool						init_map(t_game *game, char **file_path);
t_bool						init_tileset(t_game *game);
t_bool						init_player(t_game *game);
void						init_map_info(t_map_info *validate_map);
t_bool						init_exit(t_game *game);
t_bool						init_collectibles(t_game *game);

// RENDER
t_bool						render_tileset(t_game *game);
t_bool						render_player(t_game *game);
t_bool						render_closed_exit(t_game *game);
t_bool						open_exit(t_game *game);
t_bool						render_collectibles(t_game *game);

// COLLECTIBLES
void						collect_collectible(t_game *game, int32_t x,
								int32_t y);
t_bool						all_collected(t_game *game);

// TEXT MOVES
t_bool						update_moves_string(t_game *game);

// ARGUMENTS VALIDATION
t_bool						check_arguments(int argc, char **argv);

// IS TILESET TYPE
t_bool						is_floor_tile(int32_t x, int32_t y, t_game *game);
t_bool						is_collectible_tile(int32_t x, int32_t y,
								t_game *game);
t_bool						is_exit_tile(int32_t x, int32_t y, t_game *game);
t_bool						is_special_tile(int32_t x, int32_t y, t_game *game);
t_bool						is_wall_tile(int32_t x, int32_t y, t_game *game);

// PLAYER
t_bool						ft_player_move(t_game *game);

void						print_layout(t_game *game);

// MAP VALIDATION
t_bool						valid_map(t_game *game, t_map_info *validate_map);
t_bool						check_border(t_game *game);
t_bool						valid_n_items(t_map_info *validate_map);
t_bool						find_valid_path(t_game *game);
t_bool						check_line(t_game *game, char *line,
								t_map_info *validate_map);

// DISJOINT SET
t_bool						alloc_dis_item(t_dis_item **dis_item, int32_t x,
								int32_t y);
t_bool						alloc_dis_set_items(t_dis_set **dis_set,
								t_game *game);
t_bool						alloc_dis_set(t_dis_set **dis_set, t_game *game);
int32_t						get_dis_set_size(t_game *game);
t_dis_item					*find_dis_item(t_dis_item *item);
t_dis_item					*get_dis_item(t_dis_set *dis_set, int32_t x,
								int32_t y);
void						union_dis_items(t_dis_item *item1,
								t_dis_item *item2);
void						free_dis_set(t_dis_set *dis_set);

// END GAME (FREE STRUCTS)
void						end_game(t_game *game, t_bool success);
void						end_mlx(t_game *game);
void						free_collectibles(t_game *game);
void						free_exit(t_game *game);
void						free_map(t_game *game);
void						free_player(t_game *game);
void						free_tileset(t_game *game);

// HOOKS
void						ft_player_hook(t_game *game);

#endif
