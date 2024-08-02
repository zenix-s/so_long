/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                             00      +:+ +:+
	+:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:05:29 by serferna          #+#    #+#             */
/*   Updated: 2024/07/05 20:05:29 by serferna         ###   ########.fr       */
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

# define WIDTH 1024
# define HEIGHT 956

# define TILE_SIZE 64
# define CHARACTER_SPEED 205.0
# define CHARACTER_DISTANCE 64.0

typedef struct s_player
{
	size_t				init_x;
	size_t				init_y;
	size_t				score;
	int					moves;
	mlx_image_t			*img;
	int					x;
	int					y;
	int					target_x;
	int					target_y;
	int					moving;
}						t_player;

typedef struct s_enemy
{
	size_t				x;
	size_t				y;
	mlx_image_t			*img;
}						t_enemy;

typedef struct s_exit
{
	size_t				x;
	size_t				y;
	mlx_image_t			*img;
	t_bool				open;
}						t_exit;

typedef struct s_collectible
{
	size_t				x;
	size_t				y;
	mlx_image_t			*img;
}						t_collectible;

// // struct for walls, floor, etc
typedef struct s_tile
{
	size_t				x;
	size_t				y;
	mlx_image_t			*img;
	char				type;
}						t_tile;

typedef struct s_tileset
{
	t_tile				**tiles;
	size_t				n_tiles;
}						t_tileset;

typedef struct s_collectibles
{
	size_t				n_collectibles;
	t_collectible		**collectibles;
}						t_collectibles;

typedef struct s_enemies
{
	size_t				n_enemies;
	t_enemy				**enemies;
}						t_enemies;

typedef struct s_map
{
	size_t				width;
	size_t				height;
	char				**layout;
}						t_map;

typedef struct s_textures
{
	mlx_texture_t		*player;
	mlx_texture_t		*wall;
	mlx_texture_t		*floor;
	mlx_texture_t		*collectible;
}						t_textures;

typedef struct s_game
{
	mlx_t				*mlx;
	t_player			*player;
	t_map				*map;
	t_tileset			*tileset;
	t_collectibles		*collectibles;
	t_enemies			*enemies;
	t_exit				*exit;
	t_textures			*textures;
	double				last_time;
	double				time_accumulated;
	mlx_image_t			*movement;

}						t_game;

typedef struct s_validate_map
{
	t_bool				player;
	t_bool				exit;
	t_bool				collectible;
}						t_validate_map;

// Disjoint Set

typedef struct s_dis_item
{
	struct s_dis_item	*parent;
	size_t				x;
	size_t				y;
}						t_dis_item;

typedef struct s_dis_set
{
	t_dis_item			**items;
	size_t				size;
}						t_dis_set;

void					ft_error(char *msg);

// ALLOC STRUCTS
t_bool					alloc_map(t_game *game);
t_bool					alloc_tileset(t_game *game);
t_bool					alloc_collectibles(t_game *game, size_t n_collectibles);

// INIT STRUCTS
t_bool					init_game(t_game **game);
t_bool					init_map(t_game *game, char **file_path);
t_bool					init_tileset(t_game *game);
t_bool					init_collectibles(t_game *game);
t_bool					init_player(t_game *game);
void					init_validate_map(t_validate_map *validate_map);
void					init_validate_map(t_validate_map *validate_map);
t_bool					init_exit(t_game *game);

// RENDER
t_bool					render_tileset(t_game *game);
t_bool					render_collectibles(t_game *game);
t_bool					render_player(t_game *game);
t_bool					render_closed_exit(t_game *game);
t_bool					open_exit(t_game *game);

// TEXTURES
t_bool					load_textures(t_game *game);

t_bool					check_arguments(int argc, char **argv);

// MAP PARSING
t_bool					check_line(t_game *game, char *line,
							t_validate_map *validate_map);

// MLX
t_bool					init_mlx(t_game *game);

// PLAYER MOVEMENT
t_bool					ft_player_move(t_game *game);

void					print_layout(t_game *game);

// MAP VALIDATION
t_bool					valid_map(t_game *game, t_validate_map *validate_map);
t_bool					check_border(t_game *game);
t_bool					valid_n_items(t_validate_map *validate_map);
t_bool					find_valid_path(t_game *game);

// DISJOINT SET
t_bool					alloc_dis_item(t_dis_item **dis_item, size_t x,
							size_t y);
t_bool					alloc_dis_set_items(t_dis_set **dis_set, t_game *game);
t_bool					alloc_dis_set(t_dis_set **dis_set, t_game *game);
size_t					get_dis_set_size(t_game *game);
t_dis_item				*find_dis_item(t_dis_item *item);
t_dis_item				*get_dis_item(t_dis_set *dis_set, size_t x, size_t y);
void					union_dis_items(t_dis_item *item1, t_dis_item *item2);

void					end_game(t_game *game);

#endif
