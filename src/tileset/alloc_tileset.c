#include "../../include/so_long.h"

t_bool	alloc_tileset(t_game *game)
{
	size_t	width;
	size_t	height;

	width = game->map->width;
	height = game->map->height;
	game->tileset = (t_tileset *)malloc(sizeof(t_tileset));
	if (game->tileset == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	game->tileset->tiles = (t_tile **)malloc(sizeof(t_tile *) * width * height);
	if (game->tileset->tiles == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	return (TRUE);
}
