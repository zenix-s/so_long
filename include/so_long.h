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

# define TILE_SIZE 64

typedef struct s_player
{
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
	mlx_image_t		*img;
}					t_collectible;
// struct for walls, floor, etc
typedef struct s_tile
{
	mlx_image_t		*img;
	char 			type;
}					t_tile;

typedef struct s_map
{
	size_t				width;
	size_t				height;
	char			**map;
	t_enemy			**enemies;
	t_collectible	**collectibles;
	t_tile			**tiles;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_map 			*map;
}					t_game;

void				ft_error(char *msg);
void				init_player(t_game *game);

void				ft_player_move(t_game *game, char direction, int total);

#endif
