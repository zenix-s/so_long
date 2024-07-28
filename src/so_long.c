#include "../include/so_long.h"
#include <fcntl.h>
#include <stdio.h>

// HOOK
// static void	ft_hook(void *param)
// {
// 	t_game	*game;
// 	double	current_time;
// 	double	delta_time;
// 	double	time_per_move;
// 	t_bool	moved;

// 	moved = FALSE;
// 	// this function will be called every frame
// 	game = (t_game *)param;
// 	current_time = mlx_get_time();
// 	delta_time = current_time - game->last_time;
// 	game->last_time = current_time;
// 	game->time_accumulated += delta_time;
// 	// printf("time accum: %f\n", game->time_accum);
// 	time_per_move = CHARACTER_DISTANCE / CHARACTER_SPEED;
// 	// printf("time per move: %ft\n", time_per_move);
// 	if (game->time_accumulated >= time_per_move)
// 	{
// 		if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 		{
// 			ft_player_move(game, 'u', 32);
// 			moved = TRUE;
// 		}
// 		if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		{
// 			ft_player_move(game, 'd', 32);
// 			moved = TRUE;
// 		}
// 		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		{
// 			ft_player_move(game, 'l', 32);
// 			moved = TRUE;
// 		}
// 		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		{
// 			ft_player_move(game, 'r', 32);
// 			moved = TRUE;
// 		}
// 		if (moved)
// 		{
// 			printf("jackpot\n");
// 			game->time_accumulated = 0;
// 		}
// 	}
// }

// void	keyhook(mlx_key_data_t keydata, void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE)
// 		mlx_close_window(game->mlx);
// }

// // DRAW
// void	draw_green_tile(t_tile *tile)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < TILE_SIZE)
// 	{
// 		x = 0;
// 		while (x < TILE_SIZE)
// 		{
// 			mlx_put_pixel(tile->img, x, y, 0x00FF00FF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_red_tile(t_tile *tile)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < TILE_SIZE)
// 	{
// 		x = 0;
// 		while (x < TILE_SIZE)
// 		{
// 			mlx_put_pixel(tile->img, x, y, 0xFF0000FF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_blue_tile(t_tile *tile)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < TILE_SIZE)
// 	{
// 		x = 0;
// 		while (x < TILE_SIZE)
// 		{
// 			mlx_put_pixel(tile->img, x, y, 0x0000FFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_white_tile(t_tile *tile)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < TILE_SIZE)
// 	{
// 		x = 0;
// 		while (x < TILE_SIZE)
// 		{
// 			mlx_put_pixel(tile->img, x, y, 0xFFFFFFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// }





// // INIT PLAYER
// static void	draw_player(t_game *game)
// {
// 	int	i;
// 	int	x;

// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		x = 0;
// 		while (x < TILE_SIZE)
// 		{
// 			mlx_put_pixel(game->player->img, x, i, 0xFF0000FF);
// 			x++;
// 		}
// 		i++;
// 	}
// }

// void	init_player(t_game *game)
// {
// 	size_t	x;
// 	size_t	y;
// 	t_bool	player_found;

// 	player_found = FALSE;
// 	game->player = (t_player *)malloc(sizeof(t_player));
// 	if (game->player == NULL)
// 		ft_error("Failed to allocate memory for player");
// 	game->player->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
// 	if (game->player->img == NULL)
// 		ft_error("Failed to create player image");
// 	y = 0;
// 	x = 0;
// 	while (y < game->map->height && !player_found)
// 	{
// 		x = 0;
// 		while (x < game->map->width && !player_found)
// 		{
// 			if (game->map->map[y][x] == 'P')
// 			{
// 				game->map->map[y][x] = '0';
// 				player_found = TRUE;
// 			}
// 			else
// 				x++;
// 		}
// 		if (!player_found)
// 			y++;
// 	}
// 	if (!player_found)
// 		ft_error("Player starting position not found in the map");
// 	if (mlx_image_to_window(game->mlx, game->player->img, x * TILE_SIZE, y
// 			* TILE_SIZE) < 0)
// 		ft_error("Failed to display player image");
// 	draw_player(game);
// }

// int	is_within_bounds(int new_x, int new_y, t_game *game)
// {
// 	unsigned long	map_width_in_pixels;
// 	unsigned long	map_height_in_pixels;

// 	if (!game || !game->map)
// 	{
// 		printf("Error: game or game->map is NULL\n");
// 		return (0);
// 	}
// 	map_width_in_pixels = game->map->width * TILE_SIZE;
// 	map_height_in_pixels = game->map->height * TILE_SIZE;
// 	if (new_x < 0 || (unsigned int)new_x >= map_width_in_pixels || new_y < 0
// 		|| (unsigned int)new_y >= map_height_in_pixels)
// 	{
// 		printf("Position out of bounds\n");
// 		return (0); // Out of bounds
// 	}
// 	return (1); // Within bounds
// }

// int	is_walkable_tile(size_t new_x, size_t new_y, t_game *game)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < (game->map->height * game->map->width))
// 	{
// 		if (game->map->tiles[i] == NULL)
// 		{
// 			i++;
// 			continue ;
// 		}
// 		if (game->map->tiles[i]->x == new_x && game->map->tiles[i]->y == new_y)
// 		{
// 			if (game->map->tiles[i]->type == '1')
// 			{
// 				printf("Wall found\n");
// 				return (0); // Wall found
// 			}
// 			return (1); // Walkable tile
// 		}
// 		i++;
// 	}
// 	printf("No matching tile found\n");
// 	return (0); // No matching tile found (should not happen)
// }

// void	update_player_position(int new_x, int new_y, t_game *game)
// {
// 	if (!game || !game->player || !game->player->img)
// 	{
// 		printf("Error: game or game->player or game->player->img is NULL\n");
// 		return ;
// 	}
// 	game->player->img->instances[0].x = new_x;
// 	game->player->img->instances[0].y = new_y;
// }
// void	ft_player_move(t_game *game, char direction, int total)
// {
// 	int	new_x;
// 	int	new_y;

// 	if (!game || !game->player || !game->player->img)
// 	{
// 		printf("Error: game or game->player or game->player->img is NULL\n");
// 		return ;
// 	}
// 	new_x = game->player->img->instances[0].x;
// 	new_y = game->player->img->instances[0].y;
// 	// Determine new position based on direction
// 	if (direction == 'u')
// 		new_y -= total;
// 	else if (direction == 'd')
// 		new_y += total;
// 	else if (direction == 'l')
// 		new_x -= total;
// 	else if (direction == 'r')
// 		new_x += total;
// 	printf("New position: (%d, %d)\n", new_x, new_y);
// 	// Check if new position is within bounds and walkable
// 	if (is_walkable_tile(new_x, new_y, game))
// 	{
// 		update_player_position(new_x, new_y, game);
// 	}
// }

// MAIN FUNCTION
int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_game(&game))
		return (EXIT_FAILURE);
	// TODO: Load textures
	if (!load_textures(game))
		return (EXIT_FAILURE);
	if (!init_map(game, argv))
		return (EXIT_FAILURE);
	if (!init_mlx(game))
		return (EXIT_FAILURE);
	if (!init_tileset(game))
		return (EXIT_FAILURE);
	if (!init_collectibles(game))
		return (EXIT_FAILURE);
	print_layout(game);
	render_tileset(game);
	render_collectibles(game);
	// init_collectibles(game);
	// print_tiles(game);
	// print_collectibles(game);
	// init_player(game);
	// mlx_loop_hook(game->mlx, ft_hook, game);
	// mlx_key_hook(mlx_t *mlx, mlx_keyfunc func, void *param)
	// mlx_key_hook(game->mlx, &keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
