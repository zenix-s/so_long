#include "../../include/so_long.h"

t_bool	is_walkable_tile(size_t new_x, size_t new_y, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < (game->tileset->n_tiles))
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
				return (FALSE);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	is_collectible_tile(size_t new_x, size_t new_y, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < (game->collectibles->n_collectibles))
	{
		if (game->collectibles->collectibles[i]->x == new_x / TILE_SIZE
			&& game->collectibles->collectibles[i]->y == new_y / TILE_SIZE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	is_exit_tile(size_t new_x, size_t new_y, t_game *game)
{
	if ((game->exit->x * TILE_SIZE) == new_x && (game->exit->y
			* TILE_SIZE) == new_y)
		return (TRUE);
	return (FALSE);
}

void	collect_collectible(t_game *game, size_t new_x, size_t new_y)
{
	size_t	i;

	i = 0;
	while (i < (game->collectibles->n_collectibles))
	{
		if (game->collectibles->collectibles[i]->x == new_x / TILE_SIZE
			&& game->collectibles->collectibles[i]->y == new_y / TILE_SIZE)
		{
			game->collectibles->collectibles[i]->x = -1;
			game->collectibles->collectibles[i]->y = -1;
			mlx_delete_image(game->mlx,
				game->collectibles->collectibles[i]->img);
			game->collectibles->collectibles[i]->img = NULL;
			return ;
		}
		i++;
	}
}

void	update_player_position(int new_x, int new_y, t_game *game)
{
	game->player->img->instances[0].x = new_x;
	game->player->img->instances[0].y = new_y;
}

t_bool	ft_player_move(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->img->instances[0].x;
	new_y = game->player->img->instances[0].y;
	// if (direction == 'u')
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		new_y -= CHARACTER_DISTANCE;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		new_y += CHARACTER_DISTANCE;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		new_x -= CHARACTER_DISTANCE;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		new_x += CHARACTER_DISTANCE;
	else
		return (FALSE);
	if (is_walkable_tile(new_x, new_y, game))
	{
		game->player->moves++;
		if (is_collectible_tile(new_x, new_y, game))
		{
			ft_printf("Player collected a collectible!\n");
			game->player->score++;
			collect_collectible(game, new_x, new_y);
		}
		if (is_exit_tile(new_x, new_y, game))
		{
			ft_printf("Player reached the exit!\n");
			if (game->player->score == game->collectibles->n_collectibles)
				end_game(game);
			else
				return (FALSE);
		}
		update_player_position(new_x, new_y, game);
		return (TRUE);
	}
	return (FALSE);
}
