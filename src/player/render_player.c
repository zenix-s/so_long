#include "../../include/so_long.h"

t_bool	render_player(t_game *game)
{
	game->player->img = mlx_texture_to_image(game->mlx, game->textures->player);
	if (game->player->img == NULL)
		return (ft_error("Failed to create player image"), FALSE);
	if (mlx_image_to_window(game->mlx, game->player->img, game->player->target_x
			* TILE_SIZE, game->player->target_y * TILE_SIZE) < 0)
		return (ft_error("Failed to display player image"), FALSE);

	return (TRUE);
}
