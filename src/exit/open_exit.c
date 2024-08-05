#include "../../include/so_long.h"

t_bool	open_exit(t_game *game)
{

	if (game->exit->img != NULL)
		mlx_delete_image(game->mlx, game->exit->img);
	game->exit->img = mlx_texture_to_image(game->mlx,
			game->textures->exit_open);
	if (game->exit->img == NULL)
		return (ft_error("Failed to create exit image"), FALSE);
	mlx_image_to_window(game->mlx, game->exit->img, game->exit->x * TILE_SIZE,
		game->exit->y * TILE_SIZE);
	game->exit->open = TRUE;
	return (TRUE);
}
