#include "../../include/so_long.h"

t_bool	alloc_player(t_game *game)
{
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		return (ft_error("Failed to allocate memory for player"), FALSE);
	return (TRUE);
}

t_bool	find_player(t_game *game, int32_t *x, int32_t *y)
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
	int32_t	x;
	int32_t	y;

	if (!alloc_player(game))
		return (FALSE);
	if (!find_player(game, &x, &y))
		return (ft_error("Player starting position not found"), FALSE);
	game->player->target_x = x;
	game->player->target_y = y;
	game->player->moves = 0;
	game->player->score = 0;
	return (TRUE);
}
