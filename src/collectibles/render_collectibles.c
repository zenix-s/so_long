#include "../../include/so_long.h"

void	render_collectible(t_collectible *collectible)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (i + j < TILE_SIZE)
				mlx_put_pixel(collectible->img, i, j, 0xF0F00FFF);
			j++;
		}
		i++;
	}
}

t_bool	render_collectibles(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->collectibles->n_collectibles)
	{
		mlx_image_to_window(game->mlx, game->collectibles->collectibles[i]->img,
			game->collectibles->collectibles[i]->x,
			game->collectibles->collectibles[i]->y);
		render_collectible(game->collectibles->collectibles[i]);
		i++;
	}
	return (TRUE);
}
