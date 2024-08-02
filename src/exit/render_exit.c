#include "../../include/so_long.h"

t_bool	render_closed_exit(t_game *game)
{
	int	i;
	int	x;

	if (mlx_image_to_window(game->mlx, game->exit->img, game->exit->x
			* TILE_SIZE, game->exit->y * TILE_SIZE) < 0)
		return (ft_error("Failed to display player image"), FALSE);
	i = 0;
	while (i < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(game->exit->img, x, i, 0xFF0000FF);
			x++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	open_exit(t_game *game)
{
	size_t	y;
	size_t	x;

	if (game->exit->img != NULL)
		mlx_delete_image(game->mlx, game->exit->img);
	game->exit->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (game->exit->img == NULL)
		return (ft_error("Failed to create exit image"), FALSE);
	mlx_image_to_window(game->mlx, game->exit->img, game->exit->x
		* TILE_SIZE, game->exit->y * TILE_SIZE);
	game->exit->open = TRUE;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(game->exit->img, x, y, 0x00FF00FF);
			x++;
		}
		y++;
	}
	return (TRUE);
}
