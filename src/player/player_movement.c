#include "../../include/so_long.h"

t_bool	is_key_up(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx,
			MLX_KEY_W))
		return (TRUE);
	return (FALSE);
}

t_bool	is_key_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || mlx_is_key_down(game->mlx,
			MLX_KEY_S))
		return (TRUE);
	return (FALSE);
}

t_bool	is_key_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(game->mlx,
			MLX_KEY_D))
		return (TRUE);
	return (FALSE);
}

t_bool	is_key_left(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx,
			MLX_KEY_A))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_player_move(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->img->instances[0].x;
	new_y = game->player->img->instances[0].y;
	if (is_key_up(game))
		new_y -= TILE_SIZE;
	else if (is_key_down(game))
		new_y += TILE_SIZE;
	else if (is_key_left(game))
		new_x -= TILE_SIZE;
	else if (is_key_right(game))
		new_x += TILE_SIZE;
	else
		return (FALSE);
	if (is_floor_tile(new_x / TILE_SIZE, new_y / TILE_SIZE, game))
	{
		game->player->moves++;
		if (is_collectible_tile(new_x / TILE_SIZE, new_y / TILE_SIZE, game))
			collect_collectible(game, new_x / TILE_SIZE, new_y / TILE_SIZE);
		if (is_exit_tile(new_x / TILE_SIZE, new_y / TILE_SIZE, game))
		{
			if (all_collected(game))
				end_game(game, TRUE);
		}
		game->player->img->instances[0].x = new_x;
		game->player->img->instances[0].y = new_y;
		game->player->x = new_x / TILE_SIZE;
		game->player->y = new_y / TILE_SIZE;
		return (TRUE);
	}
	return (FALSE);
}
