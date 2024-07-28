#include "../../include/so_long.h"

t_bool	alloc_map(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		return (FALSE);
	game->map->layout = NULL;
	game->map->height = 0;
	game->map->width = 0;
	return (TRUE);
}
