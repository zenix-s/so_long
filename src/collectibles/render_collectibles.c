#include "../../include/so_long.h"

t_bool	render_collectibles(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->collectibles->n_collectibles)
	{
		game->collectibles->collectibles[i]->img = mlx_texture_to_image(game->mlx,
				game->textures->collectible);
		mlx_image_to_window(game->mlx, game->collectibles->collectibles[i]->img,
			game->collectibles->collectibles[i]->x * TILE_SIZE,
			game->collectibles->collectibles[i]->y * TILE_SIZE);
		i++;
	}
	return (TRUE);
}
