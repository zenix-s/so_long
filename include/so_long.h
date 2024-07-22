/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:05:29 by serferna          #+#    #+#             */
/*   Updated: 2024/07/05 20:05:29 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1024
# define HEIGHT 956

# define TILE_SIZE 32

typedef struct s_player
{
	size_t			init_x;
	size_t			init_y;
	int				score;
	int				moves;
	mlx_image_t		*img;
}					t_player;

typedef struct s_enemy
{
	mlx_image_t		*img;
}					t_enemy;

typedef struct s_collectible
{
	size_t			x;
	size_t			y;
	mlx_image_t		*img;
}					t_collectible;
// struct for walls, floor, etc
typedef struct s_tile
{
	size_t			x;
	size_t			y;
	mlx_image_t		*img;
	char			type;
}					t_tile;

typedef struct s_map
{
	size_t			width;
	size_t			height;
	char			**map;
	size_t			n_enemies;
	t_enemy			**enemies;
	size_t			n_collectibles;
	t_collectible	**collectibles;
	size_t			n_tiles;
	t_tile			**tiles;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_map			*map;
}					t_game;

void				ft_error(char *msg);


#endif
