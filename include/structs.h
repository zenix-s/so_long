/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:14:34 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 19:06:08 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTS_H

# define STRUCTS_H

// INCLUDES SECTION

// Include MLX42 library
# include "../lib/MLX42/include/MLX42/MLX42.h"

// Include libft library
# include "../lib/libft/libft.h"

// ENUMS SECTION
typedef enum s_map_node
{
	WALL = '1',
	FLOOR = '0',
	EXIT = 'E',
	COLLECTIBLE = 'C',
	PLAYER = 'P'
}							t_map_node;

// STRUCTS SECTION

// PLAYER RELATED
typedef struct s_player_texture
{
	mlx_texture_t			*frame_1;
	mlx_texture_t			*frame_2;
	mlx_texture_t			*frame_3;
	mlx_texture_t			*frame_4;
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
typedef struct s_map_node_item
{
	struct s_map_node_item	*parent;
	int32_t					x;
	int32_t					y;
	t_map_node				type;
}							t_map_node_item;

typedef struct s_map
{
	int32_t					width;
	int32_t					height;
	t_map_node_item			***layout;
	t_map_node_item			*player;
	t_map_node_item			*exit;
	t_map_node_item			**collectibles;
	int32_t					n_collectibles;
}							t_map;


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

#endif
