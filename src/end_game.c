#include "../include/so_long.h"

void	end_game(t_game *game)
{
	if (game->mlx != NULL)
		mlx_terminate(game->mlx);
	if (game != NULL)
		free(game);
	exit(0);
}
