#include "../../../include/so_long.h"

t_bool	is_exit_tile(int32_t x, int32_t y, t_game *game)
{
	if (game->map->layout[y][x] == 'E')
		return (TRUE);
	return (FALSE);
}
