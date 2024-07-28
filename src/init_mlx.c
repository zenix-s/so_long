#include "../include/so_long.h"

t_bool init_mlx(t_game *game)
{
	size_t width;
	size_t height;

	width = game->map->width * TILE_SIZE;
	height = game->map->height * TILE_SIZE;
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (false);
	return (true);
}
