#include "../../include/so_long.h"

t_bool	render_player(t_game *game)
{
	int	i;
	int	x;

	if (mlx_image_to_window(game->mlx, game->player->img, game->player->target_x
			* TILE_SIZE, game->player->target_y * TILE_SIZE) < 0)
		return (ft_error("Failed to display player image"), FALSE);
	i = 0;
	while (i < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(game->player->img, x, i, 0xFF0000FF);
			x++;
		}
		i++;
	}
	return (TRUE);
}
