#include "../../../include/so_long.h"

t_bool	is_floor_tile(int32_t x, int32_t y, t_game *game)
{
	if (game->map->layout[y][x] == '0' || game->map->layout[y][x] == 'C'
		|| game->map->layout[y][x] == 'E' || game->map->layout[y][x] == 'P')
		return (TRUE);
	return (FALSE);
}
