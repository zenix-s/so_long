#include "../../include/so_long.h"

void	free_exit(t_game *game)
{
	if (game->exit == NULL)
		return ;
	if (game->exit->img != NULL)
		mlx_delete_image(game->mlx, game->exit->img);
	free(game->exit);
}

void	free_collectibles(t_game *game)
{
	int32_t	i;

	if (game->collectibles == NULL)
		return ;
	i = 0;
	while (i < game->collectibles->n_collectibles)
	{
		if (game->collectibles->collectibles[i] != NULL)
		{
			if (game->collectibles->collectibles[i]->img != NULL)
				mlx_delete_image(game->mlx,
					game->collectibles->collectibles[i]->img);
			free(game->collectibles->collectibles[i]);
		}
		i++;
	}
	free(game->collectibles->collectibles);
	free(game->collectibles);
}

void	end_game(t_game *game, t_bool success)
{
	if (game == NULL)
		return ;
	free_exit(game);
	if (game->movement != NULL)
		mlx_delete_image(game->mlx, game->movement);
	if (game->mlx != NULL)
		mlx_terminate(game->mlx);
	if (game != NULL)
		free(game);
	if (success)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
