#include "../../include/so_long.h"

t_bool	render_collectibles(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < game->collectibles->n_collectibles)
	{
		game->collectibles->collectibles[i]->img = mlx_texture_to_image(game->mlx,
				game->collectibles->textures->collectible);
		mlx_image_to_window(game->mlx, game->collectibles->collectibles[i]->img,
			game->collectibles->collectibles[i]->x * TILE_SIZE,
			game->collectibles->collectibles[i]->y * TILE_SIZE);
		mlx_set_instance_depth(game->collectibles->collectibles[i]->img->instances,
			2);
		i++;
	}
	return (TRUE);
}
