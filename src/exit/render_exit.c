#include "../../include/so_long.h"

t_bool	render_closed_exit(t_game *game)
{
	game->exit->img = mlx_texture_to_image(game->mlx,
			game->exit->textures->exit_closed);
	if (game->exit->img == NULL)
		return (ft_error("Failed to create exit image"), FALSE);
	mlx_image_to_window(game->mlx, game->exit->img, game->exit->x * TILE_SIZE,
		game->exit->y * TILE_SIZE);
	mlx_set_instance_depth(game->exit->img->instances, 2);
	return (TRUE);
}
