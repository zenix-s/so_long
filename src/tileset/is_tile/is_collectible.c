#include "../../../include/so_long.h"

t_bool	is_collectible_tile(int32_t x, int32_t y, t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < (game->collectibles->n_collectibles))
	{
		if (game->collectibles->collectibles[i]->x == x
			&& game->collectibles->collectibles[i]->y == y)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
