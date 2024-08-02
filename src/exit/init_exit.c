#include "../../include/so_long.h"

static t_bool	alloc_exit(t_game *game)
{
	game->exit = malloc(sizeof(t_exit));
	if (game->exit == NULL)
		return (ft_error("Failed to allocate memory for exit"), FALSE);
	game->exit->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (game->exit->img == NULL)
		return (ft_error("Failed to create exit image"), FALSE);
	game->exit->open = FALSE;
	return (TRUE);
}

static void find_exit(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->layout[y][x] == 'E')
			{
				game->exit->x = x;
				game->exit->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

t_bool	init_exit(t_game *game)
{

	if (!alloc_exit(game))
		return (FALSE);
	find_exit(game);
	return (TRUE);
}
