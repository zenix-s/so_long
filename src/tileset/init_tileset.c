#include "../../include/so_long.h"

static t_bool	alloc_tileset(t_game *game)
{
	int32_t	width;
	int32_t	height;

	width = game->map->width;
	height = game->map->height;
	game->tileset = (t_tileset *)malloc(sizeof(t_tileset));
	if (game->tileset == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	game->tileset->tiles = (t_tile **)malloc(sizeof(t_tile *) * width * height);
	game->tileset->n_tiles = 0;
	if (game->tileset->tiles == NULL)
		return (ft_error("Failed to allocate memory for tileset"), FALSE);
	return (TRUE);
}

static t_bool	init_tile(t_tile **tile, char type)
{
	*tile = (t_tile *)malloc(sizeof(t_tile));
	if (*tile == NULL)
		return (ft_error("Failed to allocate memory for tile"), FALSE);
	(*tile)->img = NULL;
	(*tile)->type = type;
	return (true);
}

static t_bool	is_floor(char type)
{
	if (type == '0' || type == 'P' || type == 'E' || type == 'C')
		return (true);
	return (false);
}

static t_bool	is_wall(char type)
{
	if (type == '1')
		return (true);
	return (false);
}

t_bool	init_tileset(t_game *game)
{
	int32_t	x;
	int32_t	y;

	if (!alloc_tileset(game))
		return (FALSE);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (is_floor(game->map->layout[y][x]))
				init_tile(&game->tileset->tiles[y * game->map->width + x], '0');
			else if (is_wall(game->map->layout[y][x]))
				init_tile(&game->tileset->tiles[y * game->map->width + x], '1');
			game->tileset->tiles[y * game->map->width + x]->x = x;
			game->tileset->tiles[y * game->map->width + x]->y = y;
			x++;
		}
		y++;
	}
	game->tileset->n_tiles = game->map->height * game->map->width;
	return (TRUE);
}
