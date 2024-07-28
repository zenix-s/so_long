#include "../../include/so_long.h"

void	draw_blue_tile(t_tile *tile)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(tile->img, x, y, 0x0000FFFF);
			x++;
		}
		y++;
	}
}

void	draw_white_tile(t_tile *tile)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(tile->img, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}
t_bool	render_tileset(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->tileset->n_tiles)
	{
		mlx_image_to_window(game->mlx, game->tileset->tiles[i]->img,
			game->tileset->tiles[i]->x, game->tileset->tiles[i]->y);
		if (game->tileset->tiles[i]->type == '0')
			draw_white_tile(game->tileset->tiles[i]);
		else if (game->tileset->tiles[i]->type == '1')
			draw_blue_tile(game->tileset->tiles[i]);
		i++;
	}
	return (TRUE);
}
