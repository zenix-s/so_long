#include "../../include/so_long.h"

t_bool	render_player(t_game *game)
{
	// int	i;
	// int	x;

	// game->player->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	// if (game->player->img == NULL)
	// 	return (ft_error("Failed to create player image"), FALSE);
	// if (mlx_image_to_window(game->mlx, game->player->img, game->player->target_x
	// 		* TILE_SIZE, game->player->target_y * TILE_SIZE) < 0)
	// 	return (ft_error("Failed to display player image"), FALSE);
	// i = 0;
	// while (i < TILE_SIZE)
	// {
	// 	x = 0;
	// 	while (x < TILE_SIZE)
	// 	{
	// 		mlx_put_pixel(game->player->img, x, i, 0xFF0000FF);
	// 		x++;
	// 	}
	// 	i++;
	// }
	// game->player->img = mlx_texture_to_image(mlx_t *mlx, mlx_texture_t *texture)
	game->player->img = mlx_texture_to_image(game->mlx, game->textures->player);
	if (game->player->img == NULL)
		return (ft_error("Failed to create player image"), FALSE);
	if (mlx_image_to_window(game->mlx, game->player->img, game->player->target_x
			* TILE_SIZE, game->player->target_y * TILE_SIZE) < 0)
		return (ft_error("Failed to display player image"), FALSE);

	return (TRUE);
}
