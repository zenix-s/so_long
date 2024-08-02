#include "../../include/so_long.h"

t_bool	render_tileset(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->tileset->n_tiles)
	{
		if (game->tileset->tiles[i]->type == '0')
			game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
					game->textures->floor);
		else if (game->tileset->tiles[i]->type == '1')
			game->tileset->tiles[i]->img = mlx_texture_to_image(game->mlx,
					game->textures->wall);
		mlx_image_to_window(game->mlx, game->tileset->tiles[i]->img,
			game->tileset->tiles[i]->x, game->tileset->tiles[i]->y);
		i++;
	}
	return (TRUE);
}
