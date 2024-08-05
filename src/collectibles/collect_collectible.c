#include "../../include/so_long.h"

void	collect_collectible(t_game *game, int32_t x, int32_t y)
{
	int32_t	i;

	i = 0;
	while (i < (game->collectibles->n_collectibles))
	{
		if (game->collectibles->collectibles[i]->x == x
			&& game->collectibles->collectibles[i]->y == y
			&& game->collectibles->collectibles[i]->img != NULL)
		{
			mlx_delete_image(game->mlx,
				game->collectibles->collectibles[i]->img);
			game->collectibles->collectibles[i]->img = NULL;
			game->player->score++;
			return ;
		}
		i++;
	}
}
