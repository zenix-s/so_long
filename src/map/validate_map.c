#include "../../include/so_long.h"

// Check if the map is valid
// Valid characters: '1', '0', 'P', 'E', 'C' Alredy checked
// 'P' and 'E' must appear exactly once TODO
// 'C' must appear at least once TODO
// '1' must be the border of the map TODO
// All 'C' must be reachable from 'P' TODO

t_bool is_player_present(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->layout[y][x] == 'P')
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}

t_bool is_exit_present(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->layout[y][x] == 'E')
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}

t_bool is_collectible_present(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->layout[y][x] == 'C')
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}

t_bool is_valid_map(t_game *game)
{

}
