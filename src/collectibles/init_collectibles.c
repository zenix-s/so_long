#include "../../include/so_long.h"

static t_bool	alloc_collectibles(t_game *game, int32_t n_collectibles)
{
	game->collectibles = (t_collectibles *)malloc(sizeof(t_collectibles));
	if (game->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	game->collectibles->collectibles = (t_collectible **)malloc(sizeof(t_collectible *)
			* n_collectibles);
	if (game->collectibles->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	game->collectibles->n_collectibles = n_collectibles;
	return (TRUE);
}

static int32_t	get_number_collectibles(t_game *game)
{
	int32_t	x;
	int32_t	y;
	int32_t	n_collectibles;

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

t_bool	init_collectible(t_collectible **collectible, int32_t x, int32_t y)
{
	*collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (*collectible == NULL)
		return (ft_error("Failed to allocate memory for collectible"), FALSE);
	(*collectible)->x = x;
	(*collectible)->y = y;
	return (TRUE);
}

t_bool	init_collectibles(t_game *game)
{
	int32_t	x;
	int32_t	y;
	int32_t	i;

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
			if (!init_collectible(&game->collectibles->collectibles[i], x, y))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}
