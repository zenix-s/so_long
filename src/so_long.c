#include "../include/so_long.h"

t_bool	update_moves_string(t_game *game)
{
	char	*moves_str;

	if (game->movement != NULL)
		mlx_delete_image(game->mlx, game->movement);
	moves_str = ft_strjoin("Moves: ", ft_itoa(game->player->moves));
	if (moves_str == NULL)
	{
		ft_error("Failed to allocate memory for moves string");
		return (FALSE);
	}
	game->movement = mlx_put_string(game->mlx, (const char *)moves_str, 10, 10);
	free(moves_str);
	return (TRUE);
}

void	ft_player_hook(t_game *game)
{
	double	current_time;
	double	delta_time;
	double	time_per_move;
	t_bool	moved;

	moved = FALSE;
	current_time = mlx_get_time();
	delta_time = current_time - game->last_time;
	game->last_time = current_time;
	game->time_accumulated += delta_time;
	time_per_move = CHARACTER_DISTANCE / CHARACTER_SPEED;
	if (game->time_accumulated >= time_per_move)
	{
		if (ft_player_move(game))
			moved = TRUE;
		if (moved)
		{
			update_moves_string(game);
			game->time_accumulated = 0;
		}
	}
}

void	check_all_collectibles(t_game *game)
{
	if (game->player->score == game->collectibles->n_collectibles && game->exit->open == FALSE)
	{
		ft_printf("All collectiblees rendering exit door\n");
		(open_exit(game));
	}
}

// HOOK
static void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_player_hook(game);
	check_all_collectibles(game);
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

	game = NULL;
	if (!check_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_game(&game))
		return (EXIT_FAILURE);
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
	if (!init_exit(game))
		return (EXIT_FAILURE);
	print_layout(game);
	render_tileset(game);
	render_collectibles(game);
	render_player(game);
	render_closed_exit(game);
	update_moves_string(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
