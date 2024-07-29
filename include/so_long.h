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

# define TILE_SIZE 32
# define CHARACTER_SPEED 205.0
# define CHARACTER_DISTANCE 32.0

typedef struct s_player
{
	size_t			init_x;
	size_t			init_y;
	int				score;
	int				moves;
	mlx_image_t		*img;
	int				x;
	int				y;
	int				target_x;
	int				target_y;
	int				moving;
}					t_player;

typedef struct s_enemy
{
	size_t			x;
	size_t			y;
	mlx_image_t		*img;
}					t_enemy;

typedef struct s_collectible
{
	size_t			x;
	size_t			y;
	mlx_image_t		*img;
}					t_collectible;

// // struct for walls, floor, etc
typedef struct s_tile
{
	size_t			x;
	size_t			y;
	mlx_image_t		*img;
	char			type;
}					t_tile;

typedef struct s_tileset
{
	t_tile			**tiles;
	size_t			n_tiles;
}					t_tileset;

typedef struct s_collectibles
{
	size_t			n_collectibles;
	t_collectible	**collectibles;
}					t_collectibles;

typedef struct s_enemies
{
	size_t			n_enemies;
	t_enemy			**enemies;
}					t_enemies;

typedef struct s_map
{
	size_t			width;
	size_t			height;
	char			**layout;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_map			*map;
	t_tileset		*tileset;
	t_collectibles	*collectibles;
	t_enemies		*enemies;
	double			last_time;
	double			time_accumulated;
}					t_game;

void				ft_error(char *msg);

// ALLOC STRUCTS
t_bool				alloc_map(t_game *game);
t_bool				alloc_tileset(t_game *game);
t_bool				alloc_collectibles(t_game *game, size_t n_collectibles);

// INIT STRUCTS
t_bool				init_game(t_game **game);
t_bool				init_map(t_game *game, char **file_path);
t_bool				init_tileset(t_game *game);
t_bool				init_collectibles(t_game *game);
t_bool				init_player(t_game *game);

// RENDER
t_bool				render_tileset(t_game *game);
t_bool				render_collectibles(t_game *game);
t_bool				render_player(t_game *game);

// TEXTURES
t_bool				load_textures(t_game *game);

t_bool				check_arguments(int argc, char **argv);

// MAP PARSING
// t_bool				check_line(t_game *game, char *line);

// MLX
t_bool				init_mlx(t_game *game);

// PLAYER MOVEMENT
t_bool				ft_player_move(t_game *game, char direction, int total);

void				print_layout(t_game *game);

#endif
