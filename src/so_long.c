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
	if (all_collected(game) && game->exit->open == FALSE)
		open_exit(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

// MAIN FUNCTION

t_game	*init_game_struct(char **argv)
{
	t_game	*game;

	game = NULL;
	if (!init_game(&game))
		return (NULL);
	if (!init_map(game, argv))
		return (free(game), NULL);
	/**
		TODO: Hay que liberar game y map, en caso de error,
			esto va a ser un problema para el resto de la función
	*/
	if (!init_mlx(game))
		return (NULL);
	if (!init_map_render(game))
		return (NULL);
	if (!init_collectibles(game))
		return (NULL);
	if (!init_exit(game))
		return (NULL);
	if (!init_player(game))
		return (NULL);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_arguments(argc, argv))
		return (EXIT_FAILURE);
	game = init_game_struct(argv);
	if (game == NULL)
		return (EXIT_FAILURE);
	print_layout(game);
	render_map_render(game);
	render_collectibles(game);
	render_closed_exit(game);
	render_player(game);
	update_moves_string(game);
	mlx_loop_hook(game->mlx, ft_game_hook, game);
	mlx_loop(game->mlx);
	end_game(game, TRUE);
	return (EXIT_SUCCESS);
}
