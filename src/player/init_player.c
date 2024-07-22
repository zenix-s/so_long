#include "../../include/so_long.h"

static void	draw_player(t_game *game)
{
	int	i;
	int	x;

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
}

void	init_player(t_game *game)
{
	size_t	x;
	size_t	y;

	t_bool player_found = FALSE;
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		ft_error("Failed to allocate memory for player");
	game->player->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (game->player->img == NULL)
		ft_error("Failed to create player image");
	y = 0;
	while (y < game->map->height && !player_found)
	{
		x = 0;
		while (x < game->map->width && !player_found)
		{
			if (game->map->map[y][x] == 'P')
			{
				game->map->map[y][x] = '0';
				player_found = TRUE;
			}
			else
				x++;
		}
		if (!player_found)
			y++;
	}
	if (!player_found)
		ft_error("Player starting position not found in the map");
	if (mlx_image_to_window(game->mlx, game->player->img, x * TILE_SIZE, y
			* TILE_SIZE) < 0)
		ft_error("Failed to display player image");
	draw_player(game);
}
