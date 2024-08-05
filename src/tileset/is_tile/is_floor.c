#include "../../../include/so_long.h"

t_bool	is_floor_tile(int32_t x, int32_t y, t_game *game)
{
	int32_t	i;

	i = -1;
	while (++i < (game->tileset->n_tiles))
	{
		if (game->tileset->tiles[i] == NULL)
			continue ;
		if (game->tileset->tiles[i]->x == x && game->tileset->tiles[i]->y == y)
		{
			if (game->tileset->tiles[i]->type == '1')
				return (FALSE);
			return (TRUE);
		}
	}
	return (FALSE);
}
