#include "../include/so_long.h"

void	print_layout(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_printf("%c", game->map->layout[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
