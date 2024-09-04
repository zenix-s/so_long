#include "../../include/so_long.h"

t_bool	cacl_new_pos(t_game *game, int32_t *new_x, int32_t *new_y)
{
	*new_x = game->player->img->instances[0].x;
	*new_y = game->player->img->instances[0].y;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx,
			MLX_KEY_W))
		*new_y -= TILE_SIZE;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		*new_y += TILE_SIZE;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		*new_x -= TILE_SIZE;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		*new_x += TILE_SIZE;
	else
		return (FALSE);
	return (TRUE);
}

t_bool	ft_player_move(t_game *game)
{
	int	new_x;
	int	new_y;

	if (!cacl_new_pos(game, &new_x, &new_y))
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
