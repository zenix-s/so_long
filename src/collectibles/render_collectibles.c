#include "../../include/so_long.h"

// void	draw_collectible(t_collectible *collectible)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			if (i + j < TILE_SIZE)
// 				mlx_put_pixel(collectible->img, i, j, 0xF0F00FFF);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// // PRINT_COLLECTIBLES
// void	print_collectibles(t_game *game)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < game->map->n_collectibles)
// 	{
// 		mlx_image_to_window(game->mlx, game->map->collectibles[i]->img,
// 			game->map->collectibles[i]->x, game->map->collectibles[i]->y);
// 		draw_collectible(game->map->collectibles[i]);
// 		i++;
// 	}
// }
// t_bool	render_tileset(t_game *game)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < game->tileset->n_tiles)
// 	{
// 		mlx_image_to_window(game->mlx, game->tileset->tiles[i]->img,
// 			game->tileset->tiles[i]->x, game->tileset->tiles[i]->y);
// 		if (game->tileset->tiles[i]->type == '0')
// 			draw_white_tile(game->tileset->tiles[i]);
// 		else if (game->tileset->tiles[i]->type == '1')
// 			draw_blue_tile(game->tileset->tiles[i]);
// 		i++;
// 	}
// 	return (TRUE);
// }

void render_collectible(t_collectible *collectible)
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

t_bool render_collectibles(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->collectibles->n_collectibles)
	{
		mlx_image_to_window(game->mlx, game->collectibles->collectibles[i]->img,
			game->collectibles->collectibles[i]->x, game->collectibles->collectibles[i]->y);
		render_collectible(game->collectibles->collectibles[i]);
		i++;
	}
	return (TRUE);
}
