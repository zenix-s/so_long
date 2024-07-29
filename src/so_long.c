#include "../include/so_long.h"

// HOOK
static void	ft_hook(void *param)
{
	t_game	*game;
	double	current_time;
	double	delta_time;
	double	time_per_move;
	t_bool	moved;

	moved = FALSE;
	game = (t_game *)param;
	current_time = mlx_get_time();
	delta_time = current_time - game->last_time;
	game->last_time = current_time;
	game->time_accumulated += delta_time;
	time_per_move = CHARACTER_DISTANCE / CHARACTER_SPEED;
	if (game->time_accumulated >= time_per_move)
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		{
			ft_player_move(game, 'u', 32);
			moved = TRUE;
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		{
			ft_player_move(game, 'd', 32);
			moved = TRUE;
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		{
			ft_player_move(game, 'l', 32);
			moved = TRUE;
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		{
			ft_player_move(game, 'r', 32);
			moved = TRUE;
		}
		if (moved)
			game->time_accumulated = 0;
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

// MAIN FUNCTION
int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_game(&game))
		return (EXIT_FAILURE);
	// TODO: Load textures
	if (!load_textures(game))
		return (EXIT_FAILURE);
	if (!init_map(game, argv))
		return (EXIT_FAILURE);
	if (!init_mlx(game))
		return (EXIT_FAILURE);
	if (!init_tileset(game))
		return (EXIT_FAILURE);
	if (!init_collectibles(game))
		return (EXIT_FAILURE);
	if (!init_player(game))
		return (EXIT_FAILURE);
	print_layout(game);
	render_tileset(game);
	render_collectibles(game);
	render_player(game);

	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
