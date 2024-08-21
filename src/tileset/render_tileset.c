#include "../../include/so_long.h"
#include <stdint.h>

t_bool	render_floor(t_game *game, int32_t i);
t_bool	render_wall(t_game *game, int32_t i);
t_bool	render_tileset(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < game->tileset->n_tiles)
	{
		if (game->tileset->tiles[i]->type == '0')
			render_floor(game, i);
		else if (game->tileset->tiles[i]->type == '1')
			render_wall(game, i);
		mlx_image_to_window(game->mlx, game->tileset->tiles[i]->img,
			game->tileset->tiles[i]->x * TILE_SIZE, game->tileset->tiles[i]->y
			* TILE_SIZE);
		mlx_set_instance_depth(game->tileset->tiles[i]->img->instances, 1);
		i++;
	}
	return (TRUE);
}

t_bool	render_floor(t_game *game, int32_t i)
{
	unsigned int	rand;

	rand = gen_rand(1, 4, &game->rand_seed);
	if (rand == 1)
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->floor_2);
	else if (rand == 2)
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->floor_1);
	else
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->floor);
	return (TRUE);
}

t_bool	render_wall(t_game *game, int32_t i)
{
	if ((game->tileset->tiles[i]->y + 1) == game->map->height)
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->wall_1);
	else if (game->map->layout[game->tileset->tiles[i]->y
		+ 1][game->tileset->tiles[i]->x] != '1')
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->wall_1);
	else
		game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
				game->tileset->textures->wall);
	return (TRUE);
}
