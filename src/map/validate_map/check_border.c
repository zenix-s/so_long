#include "../../../include/so_long.h"

t_bool	check_border(t_game *game)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (y == 0 || y == game->map->height - 1)
			{
				if (game->map->layout[y][x] != '1')
					return (ft_error("Invalid map file"), FALSE);
			}
			else if (x == 0 || x == game->map->width - 1)
			{
				if (game->map->layout[y][x] != '1')
					return (ft_error("Invalid map file"), FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}
