#include "../../include/so_long.h"

t_bool	alloc_player(t_game *game)
{
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		return (ft_error("Failed to allocate memory for player"), FALSE);
	game->player->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (game->player->img == NULL)
		return (ft_error("Failed to create player image"), FALSE);
	return (TRUE);
}

t_bool	find_player(t_game *game, size_t *x, size_t *y)
{
	t_bool	player_found;

	player_found = FALSE;
	*y = 0;
	*x = 0;
	while (*y < game->map->height && !player_found)
	{
		*x = 0;
		while (*x < game->map->width && !player_found)
		{
			if (game->map->layout[*y][*x] == 'P')
				player_found = TRUE;
			else
				(*x)++;
		}
		if (!player_found)
			(*y)++;
	}
	return (player_found);
}

t_bool	init_player(t_game *game)
{
	size_t	x;
	size_t	y;

	if (!alloc_player(game))
		return (FALSE);
	if (!find_player(game, &x, &y))
		return (ft_error("Player starting position not found in the map"),
			FALSE);
	game->player->target_x = x;
	game->player->target_y = y;
	return (TRUE);
}
