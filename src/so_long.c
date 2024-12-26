/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:17 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 20:56:28 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// HOOK
static void	ft_game_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_player_hook(game);
	if (is_collectible(game, game->player->x, game->player->y))
	{
		collect_collectible(game, game->player->x, game->player->y);
	}
	if (is_exit(game, game->player->x, game->player->y) && all_collected(game))
	{
		ft_printf("You win! Moves: %d\n", game->player->moves);
		end_game(game, TRUE);
	}
	if (all_collected(game) && game->exit->open == FALSE)
	{
		open_exit(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_game(game);
		mlx_close_window(game->mlx);
	}
}

// MAIN FUNCTION

t_game	*init_game_struct(char **argv)
{
	t_game	*game;

	game = NULL;
	if (!init_game(&game))
		return (free_game(game), NULL);
	if (!init_map(game, argv))
		return (free_game(game), NULL);
	if (!init_mlx(game))
		return (free_game(game), NULL);
	if (!init_map_render(game))
		return (free_game(game), NULL);
	if (!init_collectibles(game))
		return (free_game(game), NULL);
	if (!init_exit(game))
		return (free_game(game), NULL);
	if (!init_player(game))
		return (free_game(game), NULL);
	return (game);
}

static void	render_game(t_game *game)
{
	print_layout(game);
	render_map_render(game);
	render_collectibles(game);
	render_closed_exit(game);
	render_player(game);
	update_moves_string(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_arguments(argc, argv))
	{
		return (EXIT_FAILURE);
	}
	game = init_game_struct(argv);
	if (game == NULL)
	{
		return (EXIT_FAILURE);
	}
	render_game(game);
	mlx_loop_hook(game->mlx, ft_game_hook, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
