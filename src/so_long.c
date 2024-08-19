#include "../include/so_long.h"

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
	game->player->player_time += delta_time;
	time_per_move = TILE_SIZE / CHARACTER_SPEED;
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
	if (game->player->player_time >= 0.25)
	{
		game->player->animation += 1;
		if (game->player->animation >= 4)
			game->player->animation = 0;
		// game->player->img
		mlx_delete_image(game->mlx, game->player->img);
		if (game->player->animation == 0)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->player);
		else if (game->player->animation == 1)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->player_1);
		else if (game->player->animation == 2)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->player_2);
		else if (game->player->animation == 3)
			game->player->img = mlx_texture_to_image(game->mlx,
					game->player->textures->player_3);
		mlx_image_to_window(game->mlx, game->player->img, game->player->x
			* TILE_SIZE, game->player->y * TILE_SIZE);
		game->player->player_time = 0;
	}
}

// HOOK
static void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_player_hook(game);
	if (all_collected(game) && game->exit->open == FALSE)
		open_exit(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
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
	if (!init_map(game, argv))
		return (EXIT_FAILURE);
	if (!init_mlx(game))
		return (EXIT_FAILURE);
	if (!init_tileset(game))
		return (EXIT_FAILURE);
	if (!init_collectibles(game))
		return (EXIT_FAILURE);
	if (!init_exit(game))
		return (EXIT_FAILURE);
	if (!init_player(game))
		return (EXIT_FAILURE);
	print_layout(game);
	render_tileset(game);
	render_collectibles(game);
	render_closed_exit(game);
	render_player(game);
	update_moves_string(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	end_game(game, TRUE);
	return (EXIT_SUCCESS);
}
