#include "../../include/so_long.h"

static size_t	get_number_collectibles(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	n_collectibles;

	n_collectibles = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->layout[y][x] == 'C')
				n_collectibles++;
			x++;
		}
		y++;
	}
	return (n_collectibles);
}

t_bool	init_collectible(t_collectible **collectible, t_game *game, size_t x,
		size_t y)
{
	*collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (*collectible == NULL)
		return (ft_error("Failed to allocate memory for collectible"), FALSE);
	(*collectible)->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if ((*collectible)->img == NULL)
		return (ft_error("Failed to create image for collectible"), FALSE);
	(*collectible)->x = x;
	(*collectible)->y = y;
	return (TRUE);
}

t_bool	init_collectibles(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	i;

	if (!alloc_collectibles(game, get_number_collectibles(game)))
		return (FALSE);
	i = 0;
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->layout[y][x] != 'C')
				continue ;
			printf("Collectible found at (%zu, %zu)\n", x, y);
			if (!init_collectible(&game->collectibles->collectibles[i], game, x
					* TILE_SIZE, y * TILE_SIZE))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}
