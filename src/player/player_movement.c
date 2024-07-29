#include "../../include/so_long.h"

t_bool	is_walkable_tile(size_t new_x, size_t new_y, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < (game->map->height * game->map->width))
	{
		if (game->tileset->tiles[i] == NULL)
		{
			i++;
			continue ;
		}
		if (game->tileset->tiles[i]->x == new_x
			&& game->tileset->tiles[i]->y == new_y)
		{
			if (game->tileset->tiles[i]->type == '1')
				return (ft_error("Wall found"), FALSE);
			return (TRUE);
		}
		i++;
	}
	printf("No matching tile found\n");
	return (ft_error("No matching tile found"), FALSE);
}

void	update_player_position(int new_x, int new_y, t_game *game)
{
	game->player->img->instances[0].x = new_x;
	game->player->img->instances[0].y = new_y;
}

t_bool	ft_player_move(t_game *game, char direction, int total)
{
	int	new_x;
	int	new_y;

	new_x = game->player->img->instances[0].x;
	new_y = game->player->img->instances[0].y;
	// Determine new position based on direction
	if (direction == 'u')
		new_y -= total;
	else if (direction == 'd')
		new_y += total;
	else if (direction == 'l')
		new_x -= total;
	else if (direction == 'r')
		new_x += total;
	// Check if new position is within bounds and walkable
	if (is_walkable_tile(new_x, new_y, game))
	{
		update_player_position(new_x, new_y, game);
		return (TRUE);
	}
	return (FALSE);
}
